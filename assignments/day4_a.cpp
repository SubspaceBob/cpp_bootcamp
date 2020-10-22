#include <iostream>

class Shape {
protected:
    int width, height;
public:    
    Shape(int a, int b) {width=a; height=b;}  
    virtual int area(){};// = 0;
    virtual int Perimeter(){return this->width;}; // if not overridden by child
    
    bool operator== (Shape &c2){
        if (this->area() == c2.area()){
            std::cout << "same area, maybe same perimeter??" << std::endl;
            return this->Perimeter() == c2.Perimeter();
        }
        std::cout << "Not same area" << std::endl;
        return false;
    }

    bool operator> (Shape &c2){
    return this->area() > c2.area();
    }

    bool operator<(Shape &c2){
        return this->area() < c2.area();
    } 
};

class Circle : public Shape{
public:
    Circle(int a, int b) : Shape(a, b){} 
    int area () {return this->width * this->height * 3.141592 /4;} // Area of ellipse
    int Perimeter(){return this->height*3.141592;}  // Overrides Shape::Perimeter
};

class Triangle : public Shape { 
public:
    Triangle(int a, int b) : Shape(a, b){}  
    int area () override {return this->width * this->height /2;} // Area of triangle
};


int main() {
    Shape **p;

    p = new Shape*[4];
    p[0] = new Circle(4,4);
    p[1] = new Triangle(4,4);
    p[2] = new Circle(6,2);
    p[3] = new Triangle(6,4);
    *p[0] == *p[1];
    std::cout << "circle_4_4 == Triangle_4_4 : " << (*p[0] == *p[1]) << std::endl;
    std::cout << "circle_6_2 == Triangle_4_4 : " << (*p[2] == *p[1]) << std::endl;
    std::cout << "circle_4_4 < Triangle_4_4 : " << (*p[0] < *p[1]) << std::endl;
    std::cout << "circle_4_4 == circle_6_2 : " << (*p[0] == *p[2]) << std::endl;
    std::cout << "circle_4_4 > circle_6_2 : " << (*p[0] > *p[2]) << std::endl;
    std::cout << "Triangle_6_4 == Circle_4_4 : " << (*p[3] == *p[0]) << std::endl;

    for (size_t i = 0; i < 4; i++) {
        std::cout << p[i]->area() <<std::endl;
        delete p[i]; 
    }
    
    return 0;

}