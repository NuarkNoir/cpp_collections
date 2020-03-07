#ifndef NN_COLLS_VECTOR
#define NN_COLLS_VECTOR

#include <type_traits>

template <typename T>
class vector
{
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
    vector() {
        this->_reallocate_mem();
    }
    vector(std::size_t initial_capacity) :_capacity(initial_capacity) {
        this->_reallocate_mem();
    }
    vector(std::size_t initial_capacity, T default_element) :_capacity(initial_capacity) {
        this->assign(initial_capacity, default_element);
    }
    virtual ~vector() {
        delete[] this->elements;
    }

    void assign(std::size_t count, T element) {
        this->_reallocate_mem();
        for (std::size_t i = 0; i < count; i++) {
            this->elements[i] = element;
        }
        this->_size = count;
    }

    void push_back(T element) {
        if (this->_size + 1 > this->_capacity) {
            this->extend_size(this->_capacity * 1.5);
        }
        this->elements[this->_size++] = element;
    }

    void pop_back() {
        this->resize(this->_size-1);
    }

    //TODO: assertion test
    vector& operator=(vector&& other) {
        this->clear();
        this->_capacity = other.capacity();
        for (std::size_t i = 0; i < this->_capacity; i++) {
            this->push_back(other[i]);
        }
        return *this;
    }

    T& at(std::size_t idx) {
        if (idx >= this->_size) {
            throw "out_of_range";
        }
        return this->elements[idx];
    }

    T& operator[] (std::size_t idx) {
        return this->elements[idx];
    }

    T& front() {
        return this->elements[0];
    }

    T& back() {
        return this->elements[this->_size-1];
    }

    T* data() {
        return this->elements;
    };

    std::size_t size() {
        return this->_size;
    }

    std::size_t capacity() {
        return this->_capacity;
    }

    bool empty() {
        return this->_size == 0;
    }

    void erase(std::size_t first, std::size_t last) {
        std::size_t ec = 0; 
        auto nm = new T[this->_size];
        for (std::size_t i = 0; i < this->_size; i++) {
            if (i >= first && i < last) continue;
            nm[ec++] = this->elements[i];
        }
        this->_size = ec;
        delete[] this->elements;
        this->elements = nm;
    }

    void erase(std::size_t pos) {
        this->erase(pos, pos+1);
    }

    void clear() {
        this->_size = 0;
        this->_reallocate_mem();
    }

    void insert(std::size_t pos, const T& value) {
        if (pos >= this->_size) {
            throw "out_of_range";
        }
        if (this->_size + 1 > this->_capacity) {
            this->_capacity = this->_capacity + 1;
            this->_reallocate_mem();
        }
        for (std::size_t i = this->_size; i > pos; i--) {
            this->swap(i, i-1);
        }
        this->elements[pos] = value;
        this->_size += 1;
    }

    void swap(std::size_t pos1, std::size_t pos2) {
        auto tmp = this->elements[pos1];
        this->elements[pos1] = this->elements[pos2];
        this->elements[pos2] = tmp;
    }

    bool extend_size(std::size_t new_size) {
        if (new_size < this->_capacity) {
            return false;
        }
        this->_capacity = new_size;
        this->_reallocate_mem();
        return true;
    }

    void shrink_to_fit() {
        if (this->_size < this->_capacity) {
            this->_capacity = this->_size;
            this->_reallocate_mem();
        }
    }

    void resize(std::size_t count) {
        this->_capacity = count;
        if (count < this->_size) {
            this->_size = count;
        }
        this->_reallocate_mem();
    }

    void resize(std::size_t count, const T& value) {
        bool mo = this->_size - count;
        this->resize(count);
        if (mo > 0) {
            for (int i = 0; i < mo; i++) {
                this->push_back(value);
            }
        }
    }
};


#endif