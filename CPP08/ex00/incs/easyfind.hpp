#pragma once
#include <algorithm>
#include <vector>
#include <exception>
#include <stdexcept>
#include <iostream>

template <typename T>

typename T::iterator	easyfind(T& bucket, const int& toFind)
{
	typename T::iterator found = std::find(bucket.begin(), bucket.end(), toFind);
	if (found == bucket.end())
		throw std::runtime_error("Could not find the element in the container");
	std::cout << "found " << *found << std::endl;
	return (found);
}
