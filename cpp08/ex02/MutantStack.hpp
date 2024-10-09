#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T> {

public:
    using std::stack<T>::c;

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() {
        return c.begin();
    }

    iterator end() {
        return c.end();
    }
};