#include "func.h"

double Square ::Area()
{
    return length * length;
}

void Square ::Show()
{
    cout << "\nДлина:" << length << ", координата по x" << x << ", координата по y" << y << ", угол на который поверут квадрат" << angle;
}

void Square::AddVector(double x1, double y1)
{
    x += x1;
    y += y1;
}
void Square::increase(double k)
{
    length = length * k;
}
bool operator==(Square tri1, Square tri2)
{
    return tri1.Area() == tri2.Area();
}
bool operator!=(Square tri1, Square tri2)
{
    return tri1.Area() != tri2.Area();
}
bool operator>(Square tri1, Square tri2)
{
    return tri1.Area() > tri2.Area();
}
bool operator<(Square tri1, Square tri2)
{
    return tri1.Area() < tri2.Area();
}

Array Array::operator+( Array &other)
{
    Array tmp;
    Array oth=other;

    for (int i = 0; i < 10; i++)
    {
        if (this->array[i] != 11)
        {

            tmp.array[i] = this->array[i];
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (oth.array[i] != 11)
        {

            tmp.array[i] = this->array[i];
        }
    }
    return tmp;
}
void Array::Show()
{
    cout << "\n";
    for (int i = 0; i < 10; i++)
    {
        if((0<=array[i]) && (array[i]<11))
        {
            cout << array[i] << " ";
        }
    }
}

bool Array::operator==(Array & mas2)
{

    for (int i = 0; i < 10; i++)
    {
        if (this->array[i] != mas2.array[i])
        {
            return false;
            break;
        }
    }
    return true;
}
bool Array::operator!=(Array &mas2)
{
    for (int i = 0; i < 10; i++)
    {
        if (this->array[i] != mas2.array[i])
        {
            return true;
            break;
        }
    }
    return false;
}
void Array::operator+=(int x)
{
    array[x]=x;
}
void Array::operator-=(int x)
{
    array[x]=11;
}
void Array::operator=(Array &other)
{
    int n = 10;
    for (int i = 0; i < n;i++){
        this->array[i] = other.array[i];
    }
}
