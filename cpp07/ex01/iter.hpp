#include <iostream>

template<typename T, typename Func>
void iter(T* arr, size_t length, Func func)
{
    for(size_t i = 0; i < length ; i++)
    {
        func(arr[i]);
    }
}

template<typename T, typename Func>
void iter(const T* arr, size_t length, Func func)
{
    for(size_t i = 0; i < length ; i++)
    {
        func(const_cast<T&>(arr[i]));
    }
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}