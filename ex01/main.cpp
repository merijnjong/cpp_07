#include <iostream>

#include "iter.hpp"

class SampleItem
{
public:
	SampleItem(void) : _n(42) {}
	int get(void) const { return this->_n; }

private:
	int _n;
};

std::ostream &operator<<(std::ostream &o, SampleItem const &rhs)
{
	o << rhs.get();
	return o;
}

template <typename T>
void print(T const &x)
{
	std::cout << x << std::endl;
}

void increment(int &value)
{
	++value;
}

int main(void)
{
	int tab[] = {0, 1, 2, 3, 4};
	SampleItem tab2[5];

	::iter(tab, 5, print<int>);
	::iter(tab2, 5, print<SampleItem>);

	::iter(tab, 5, increment);
	std::cout << "---" << std::endl;
	::iter(tab, 5, print<int>);

	const int readonly[] = {10, 20, 30};
	std::cout << "---" << std::endl;
	::iter(readonly, 3, print<int>);

	return 0;
}
