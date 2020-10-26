#ifndef ringbuffer_H
#define ringbuffer_H
#include<iostream>

class RingBuffer{
private:
    int index_next_read = 0;
    int index_next_write = 0;
    int buffer[20]; // size, for now
public: 
    RingBuffer() = default;
    ~RingBuffer(){
        std::cout << "Deleting element" << this << std::endl;
        delete this->buffer;
    }   

    void put(int input){
        this->buffer[this->index_next_write] = input;
        index_next_write++%20;
    }

    auto get(int input){
        return this->buffer[this->index_next_read];
        index_next_read++%20;
    }
};
#endif // ringbuffer_H