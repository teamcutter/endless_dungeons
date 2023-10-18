#pragma once
#include <string>

class Point {
private:
    float _x, _y;
public:
    Point(float x = 0, float y = 0): _x(x), _y(y) {}

    float GetX();
    float GetY();

    // Setters 
    void SetX(float x);
    void SetY(float y);

    // Operators
    Point operator+(const Point& p2) const;
    friend Point operator+=(Point& p1, const Point& p2);
    Point operator-(const Point& p2) const;
    friend Point operator-=(Point& p1, const Point& p2);
    Point operator*(const float scal) const;

    // Debugging
    void Log(std::string message);
};