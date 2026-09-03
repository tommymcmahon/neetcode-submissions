#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class DynamicArray {
   public:
    DynamicArray(int capacity) : capacity_(capacity),  size_(0), data_(new int[capacity_]) { }

    int get(int i) 
    {
        return data_[i];
    }

    void set(int i, int n) 
    { 
        data_[i] = n; 
    } 

    void pushback(int n) 
    { 
        if (size_ == capacity_) {
            resize();   
        }
        data_[size_] = n;
        size_++;
    }

    int popback() 
    {
        if (size_ > 0) {
            size_--;
        }
        return data_[size_];
    }

    void resize() 
    {
        // Double the size of the array
        capacity_ *= 2;

        // allocate new array
        int* tmp = new int[capacity_]; 

        // memcopy
        std::memcpy(tmp, data_, size_ * sizeof(int));

        // swap
        std::swap(tmp, data_);

        // delete the old array
        delete [] tmp;
        tmp = nullptr;
    }

    int getSize() { return size_; }

    int getCapacity() { return capacity_; }

private:

    uint64_t capacity_;
    uint64_t size_;
    int *data_;
};
