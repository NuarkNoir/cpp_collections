#ifndef NN_COLLS_CONTAINER
#define NN_COLLS_CONTAINER

#include <type_traits>

template <typename T>
class container {
static_assert(std::is_pod<T>::value, "T must be POD");

private:
    std::size_t _size = 0;
    std::size_t _capacity = 20;
    T* elements = nullptr;

    void _reallocate_mem() {
        T* tmp = new T[this->_capacity];
        if (this->elements != nullptr) {
            for (std::size_t i = 0; i < this->_size; i++) {
                tmp[i] = T(this->elements[i]);
            }
        }
        delete[] this->elements;
        this->elements = tmp;
    }

public:
    container() {
        this->_reallocate_mem();
    }
    container(std::size_t initial_capacity) :_capacity(initial_capacity) {
        this->_reallocate_mem();
    }
    container(std::size_t initial_capacity, T default_element) :_capacity(initial_capacity) {
        this->assign(initial_capacity, default_element);
    }
    virtual ~container() {
        delete[] this->elements;
    }
    
    void init() {
        _reallocate_mem();
    }

    std::size_t size() {
        return this->_size;
    }

    std::size_t capacity() {
        return this->_capacity;
    }

    bool empty() {
        return this->_size == 0;
    }
};


#endif 