#include <algorithm>

template<typename T>

bool easyfind(T container, int value) {
    typename T::iterator it  = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        return true;
    else
        return false;
}