#ifndef A1_2_H
#define A1_2_H
#include<iostream>
#include <bitset>

struct vehicle_status {
    unsigned  belts:5;
    unsigned  windows:4;
    unsigned  doors:4;
    unsigned  lights:3;           
};

struct assignment_2 {
    unsigned left : 3;
    unsigned right : 3;
    unsigned rear : 3;
    unsigned front : 3;
    unsigned speed : 4;

};

uint16_t Encode(uint speed, uint front, uint rear, uint right, uint left){
    // takes 5 inputs and returns a uint16
    assignment_2 data = assignment_2();
    
    data.speed = speed / 20;
    data.front = front / 150;     // only 3 bits, some masking needed
    data.rear = rear / 150;       // only 3 bits, some masking needed
    data.right = right / 150;     // only 3 bits, some masking needed
    data.left = left /150;       // only 3 bits, some masking needed

    std::cout << "Speed " << data.speed << " " << std::bitset<4>(data.speed) << std::endl;
    std::cout << "front " << data.front << " " << std::bitset<3>(data.front) << std::endl;
    std::cout << "rear "  << data.rear  << " " << std::bitset<3>(data.rear) << std::endl;
    std::cout << "right " << data.right << " " << std::bitset<3>(data.right) << std::endl;
    std::cout << "left "  << data.left  << " " << std::bitset<3>(data.left) << std::endl;
    
    uint16_t *result;
    result = reinterpret_cast<uint16_t*>(&data);
    return *result;
};

void get_speed(uint16_t input){
    assignment_2 *data;
    data = reinterpret_cast<assignment_2*>(&input);
    std::cout << "Reading speed : " << data->speed << std::endl;
} 

void detectCrash(uint16_t input){
    // determines if we have collided
    auto all_distance_bits = std::bitset<16>(input & 0b0000111111111111);
    auto front_sensor = std::bitset<3>((input & 0b0000111000000000) >> 9);
    auto rear_sensor  = std::bitset<3>((input & 0b0000000111000000) >> 6);
    auto right_sensor = std::bitset<3>((input & 0b0000000000111000) >> 3);
    auto left_sensor  = std::bitset<3>((input & 0b0000000000000111));
    //if(!*input & 0b0000111111111111) { 
    std::cout << all_distance_bits  << std::endl;
    std::cout << front_sensor << std::endl;
    std::cout << rear_sensor << std::endl;
    std::cout << right_sensor << std::endl;
    std::cout << left_sensor << std::endl;
    if (front_sensor == 0){
        std::cout << "Front crash!"<< std::endl;
    } 
    if (rear_sensor == 0){
        std::cout << "Rear crash!"<< std::endl;
    } 
    if (right_sensor == 0){
        std::cout << "Right crash!"<< std::endl;
    } 
    if (left_sensor == 0){
        std::cout << "Left crash!"<< std::endl;
    } 
    get_speed(input);

} 

void print_vehicle_status(uint16_t *v){ 
    std::cout << "Printing Vehicle Status" << std::endl;
 
    vehicle_status *d;
    d = reinterpret_cast<vehicle_status*>(v);
    std::cout << "Belts " << d->belts << std::endl;
    std::cout << "windows " << d->windows << std::endl;
    std::cout << "doors " << d->doors << std::endl;
    std::cout << "lights " << d->lights << std::endl;
    std::cout << "----------------" << std::endl;
    
} 

#endif // A1_2_H