#ifndef CPP_COLLECTIONS_STACK_H
#define CPP_COLLECTIONS_STACK_H

#include <type_traits>

template <typename T>
class stack {
static_assert(std::is_pod<T>::value, "T must be POD");

private:
    struct _wrapper {
        T data;
        _wrapper* prev;
    };

    std::size_t _size = 0;
    _wrapper* tail = nullptr;

public:
    stack() = default;
    virtual ~stack() {
        this->clear();
    }

    void push(T item) {
        auto nw = new _wrapper();
        nw->data = item;
        nw->prev = this->tail;
        this->tail = nw;
        this->_size += 1;
    }

    T pop() {
        auto lw = this->tail;
        auto data = lw->data;
        this->tail = lw->prev;
        delete lw;
        this->_size -= 1;
        return data;
    }

    std::size_t size() {
        return this->_size;
    }

    void clear() {
        while (this->tail != nullptr) {
            this->pop();
        }
    }
};

#endif //CPP_COLLECTIONS_STACK_H
