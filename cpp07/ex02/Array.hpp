#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>


template <typename T>

class Array {

    private:
        T *_array;
        unsigned int _size;

    public:
        Array() : _array(new T()), _size(1) {}

        Array(unsigned int n) : _size(n)
        {
            if (n == 0)
                throw std::runtime_error("Size is not to be Zero :(");
            
            _array = new T[_size];
            for (size_t i = 0; i < _size; i++)
                _array[i] = T();
        }

        Array(const Array &r) : _size(r._size)
        {
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                _array[i] = r._array[i];
        }

        Array &operator=(const Array &r)
        {
            if (this != &r) {
                delete[] _array;
                _size = r._size;
                _array = new T[_size];
                for (unsigned int i = 0; i < _size; ++i)
                    _array[i] = r._array[i];
            }
            return *this;
        }

        T &operator[](unsigned int index)
        {
            if (index >= _size)
                throw std::runtime_error("Index out of bounds :(");
            return _array[index];
        }

        unsigned int size() const
        {
            return _size;
        }

        ~Array()
        {
            std::cout << "Array bye bye :)" << std::endl;
            delete[] _array;
        }
};
#endif