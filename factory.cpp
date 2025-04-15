#include <iostream>
#include <cmath>
using namespace std;


class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};


class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

class Square : public Shape {
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};


class ShapeCreator {
public:
    virtual Shape* factoryMethod(double a, double b = 0) = 0;
    virtual ~ShapeCreator() = default;
};


class CircleCreator : public ShapeCreator {
public:
    Shape* factoryMethod(double radius, double b = 0) override {
        return new Circle(radius);
    }
};

class SquareCreator : public ShapeCreator {
public:
    Shape* factoryMethod(double side, double b = 0) override {
        return new Square(side);
    }
};

class RectangleCreator : public ShapeCreator {
public:
    Shape* factoryMethod(double width, double height = 0) override {
        return new Rectangle(width, height);
    }
};


int main() {
    
    CircleCreator circleCreator;
    Shape* circle = circleCreator.factoryMethod(3.0);
    cout << "Circle Area: " << circle->area() << endl;
    delete circle;

    
    SquareCreator squareCreator;
    Shape* square = squareCreator.factoryMethod(4.0);
    cout << "Square Area: " << square->area() << endl;
    delete square;

    
    RectangleCreator rectangleCreator;
    Shape* rectangle = rectangleCreator.factoryMethod(3.0, 5.0);
    cout << "Rectangle Area: " << rectangle->area() << endl;
    delete rectangle;

    return 0;
}
