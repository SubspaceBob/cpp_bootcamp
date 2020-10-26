#include "a1_2.h"
int main(){
    // assignment 1
    uint16_t v = 0b0101110100110010;
    print_vehicle_status(&v);
    
    
    // Assignment 2
    uint16_t encoded = Encode(85, 440, 1050, 60, 130);

    detectCrash(encoded);
    
    std::cout << "----------------" << std::endl;
    return 0;
}