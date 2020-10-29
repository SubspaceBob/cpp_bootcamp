#include "shape.h"
#include "comp_func.h"
#include "cassert"

void test_circle_0(){
    Circle *small_circle = new Circle(5);
    Circle *large_circle = new Circle(6);
    
    assert(small_circle == large_circle);
    //assert(small_circle->Area); // try access private property.

    std::cout << "done" << std::flush;
    delete small_circle, large_circle;
}

int main(){
    test_circle_0();


}