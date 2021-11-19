#pragma once
#include <iostream>

template<typename T>
class Vector {
public:
    Vector() = default;
    Vector(Vector& other) {
        if (this != &other) {
            if (arr_) delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
    }
    Vector(Vector&& other) {
        if (this != &other) {
            if (arr_) delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
    }
    Vector& operator=(Vector& other) {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
        return *this;
    }

    Vector& operator=(Vector&& other) {
        if (this != &other) {
            delete[] arr_;
            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.arr_ = nullptr;
            other.size_ = other.capacity_ = 0;
        }
        return *this;
    }

    ~Vector() {
        delete[] arr_;
    }
public:
    [[nodiscard]] bool isEmpty() const {
        return size_ == 0;
    }

    [[nodiscard]] size_t size() const {
        return size_;
    }

    void pushBack(const T& value) {
        if (size_ >= capacity_) addMemory();
        arr_[size_++] = value;
    }

    T& operator[](size_t index)  {
        return arr_[index];
    }

    const T& operator[](size_t index) const {
        return arr_[index];
    }
private:

    void addMemory() {
        if (capacity_ == 0) capacity_ = 1;
        capacity_ *= 2;
        T* tmp = arr_;
        arr_ = new T[capacity_];
        for (int i = 0; i < size_; ++i) arr_[i] = tmp[i];
    }

    T* arr_;
    size_t size_;
    size_t capacity_;
};

template<typename T>
inline std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) os << vec[i] << " ";
    return os;
}
