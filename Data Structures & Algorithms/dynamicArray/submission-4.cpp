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

        for (int i = 0; i < size_; i++) {
            tmp[i] = data_[i];
        }

        // delete the old array
        delete [] data_;

        // assign the new array  
        data_ = tmp;
    }

    int getSize() { return size_; }

    int getCapacity() { return capacity_; }

private:

    uint64_t capacity_;
    uint64_t size_;
    int *data_;
};
