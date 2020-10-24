#ifndef COMP_FUNC_H
#define COMP_FUNC_H
#include "shape.h"
#include <iostream>

template <typename T>
void compare_equal(const T &_a, const T &_b) {   
    std::cout << (&_a == &_b ?  " Equal " : " Not Equal "); 
}

template <typename T>
void compare_less(const T &_a, const T &_b) {   
    std::cout << (&_a < &_b ?  " Less " : " Not less "); 
}

template <typename T>
void compare_more(const T &_a, const T &_b) {   
    std::cout << (&_a > &_b ?  " More " : " Not more "); 
}

#endif // COMP_FUNC_H