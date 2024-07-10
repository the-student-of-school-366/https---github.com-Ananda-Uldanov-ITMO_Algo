#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class Square
{
private:
    double x;
    double y;
    double length;
    double angle;

public:
    Square(double x, double y, double length, double angle) : x(x), y(y), length(length), angle(angle) {}

    Square() : x(0), y(0), length(0), angle(0) {}

    ~Square() = default;
    double Area();
    void Show();
    void increase(double k);
    void AddVector(double x, double y);
};

class Array
{
private:
    int *array;
    int MAX;

public:
    Array()
    {
        array = new int[10];
        for(int i=0;i<10;i++)
        {
            array[i]=11;
        }
        MAX = -1;
    }
    ~Array()
    {
        delete[] array;
    }
    Array operator+(Array &other);
    bool operator==(Array &other);
    bool operator!=(Array &other);
    void operator+=(int x);
    void operator-=(int x);
    void Show();
    void operator=(Array &other);

};