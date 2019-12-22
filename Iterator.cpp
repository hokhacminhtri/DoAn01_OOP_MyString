#include "Iterator.h"

Iterator::Iterator(int* x) :p(x)
{

}

Iterator::Iterator(const Iterator& mit) : p(mit.p)
{

}

Iterator& Iterator::operator++()
{
	p++; 
	return *this;
}

Iterator Iterator::operator++(int)
{
	Iterator tmp(*this);
	operator++();
	return tmp;
}

bool Iterator::operator==(const Iterator& rhs) const
{
	return p == rhs.p;
}

bool Iterator::operator!=(const Iterator& rhs) const
{
	return p == rhs.p;
}

int& Iterator::operator*()
{
	return *p;
}
