#ifndef NN_COLLS_CONTAINER
#define NN_COLLS_CONTAINER

#include <type_traits>

template <typename T>
class container {
static_assert(std::is_pod<T>::value, "T must be POD");

private:
    int _size = 0;
    int _capacity = 20;
    T* elements = nullptr;

public:
    virtual ~container() {
        delete[] this->elements;
    }

    int size() {
        return this->_size;
    }

    int capacity() {
        return this->_capacity;
    }

    bool empty() {
        return this->_size == 0;
    }
};


#endif 