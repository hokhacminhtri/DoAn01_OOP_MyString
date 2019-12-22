#pragma once

#ifndef _ITERATOR_
#define _ITERATOR_

#include <iostream>
#include <iterator>

class Iterator :public std::iterator<std::input_iterator_tag, int>
{
private:
	int* p;
public:
	Iterator(int* x);
	Iterator(const Iterator& mit);
	Iterator& operator++();
	Iterator operator++(int);
	bool operator==(const Iterator& rhs) const;
	bool operator!=(const Iterator& rhs) const;
	int& operator*();
};

#endif

