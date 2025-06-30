#pragma once

template <typename T, typename F>
void	iter(T* array, unsigned int size, F f)
{
	if (!array || !f)
		return ;
	for (unsigned int i = 0; i < size; i++)
		(*f)(array[i]);
}

//template <typename T>
//void	iter(T* array, unsigned int size, void (*f)(const T&))
//{
//	if (!array || !f)
//		return ;
//	for (unsigned int i = 0; i < size; i++)
//		(*f)(array[i]);
//}
