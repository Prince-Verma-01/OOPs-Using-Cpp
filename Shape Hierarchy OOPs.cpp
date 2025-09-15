#include <iostream>
#include <string>
using namespace std;

class Shape{
public:
    string name;
    virtual double area() = 0;
    virtual double perimeter() = 0;
    
};

class Circle : public Shape{
public :
    double radius;
    
    // CONSTRUCTOR
    Circle(double radius){
        this->radius = radius;
    }
    
    //AREA
    double area(){
        double area = 3.14*radius*radius;
        return area;
    }
    
    //PERIMETER
    double perimeter(){
        double perimeter = 2*3.14*radius;
        return perimeter;
    }
};

class Square : public Shape{
public:
    double side;
    
    //CONSTRUCTOR
    Square(double side){
        this->side = side;
    }
    
    // AREA
    double area(){
        double area = side*side;
        return area;
    }
    
    //PERIMETER
    double perimeter(){
        double perimeter = 4*side;
        return perimeter;
    }
};

class Rectangle : public Shape{
public:
    double length;
    double width;
    
    //CONSTRUCTOR
    Rectangle(double length, double width){
        this->length = length;
        this->width = width;
    }
    
    // AREA
    double area(){
        double area = length*width;
        return area;
    }
    
    //PERIMETER
    double perimeter(){
        double perimeter = 2*(length+width);
        return perimeter;
    }
};

int main()
{
    Shape* shapes[3];
    shapes[0] = new  Circle(8);
    shapes[1] = new Square(5);
    shapes[2] = new Rectangle(5, 10);
    
    for(int i = 0; i < 3; i++){
        if(i == 0){
            cout << "Circle :\n";
        } else if(i == 1){
            cout << "Square :\n";
        } else if(i == 2){
            cout << "Rectangle :\n";
        }
        
        cout << "Area : " << shapes[i]->area() << endl; 
        cout << "Perimeter : " << shapes[i]->perimeter() << endl; 
        cout << "_______________________\n";
    }
    
    for(int i = 0; i < 3; i++){
        delete shapes[i];
    }
    return 0;
}

