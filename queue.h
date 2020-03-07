#ifndef NN_COLLS_QUEUE
#define NN_COLLS_QUEUE

#include <type_traits>

template <typename T>
class queue {
static_assert(std::is_pod<T>::value, "T must be POD");

private:
    int _size = 0;
    int _capacity = 20;
    T* elements = nullptr;

    void _reallocate_mem() {
        T* tmp = new T[this->_capacity];
        if (this->elements != nullptr) {
            for (int i = 0; i < this->_size; i++) {
                tmp[i] = T(this->elements[i]);
            }
        }
        delete[] this->elements;
        this->elements = tmp;
    }

public:
    queue() {
        this->_reallocate_mem();
    }
    queue(int initial_capacity) :_capacity(initial_capacity) {
        this->_reallocate_mem();
    }
    virtual ~queue() {
        delete[] this->elements;
    }

    void push(T element) {
        if (this->_size + 1 > this->_capacity) {
            this->extend_size(this->_capacity * 1.5);
        }
        this->elements[this->_size++] = element;
    }

    T pop() {
        if (--this->_size < 0) {
            this->_size = 0;
            throw "empty list";
        }
        return *(this->elements + (this->_size));
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

    void clear() {
        this->_size = 0;
        this->_reallocate_mem();
    }

    bool extend_size(int new_size) {
        if (new_size < this->_capacity) {
            return false;
        }
        this->_capacity = new_size;
        this->_reallocate_mem();
        return true;
    }
};


#endif 