#include "func.h"


void Circle ::initFromDialog()
{
    cout << "Enter your radius = ";
    cin >> radius;
    cout << "Enter your density = ";
    cin >> p;
    cout << "Enter your centre = ";
    cin >> centre.x >> centre.y;
}

const char *Circle ::classname()
{
    return "Circle";
}

unsigned int Circle ::size()
{
    return sizeof(*this);
}

double Circle ::square()
{
    return radius * radius * 3, 14;
}

double Circle ::perimeter()
{
    return 2 * radius * 3, 14;
}

double Circle ::mass()
{
    return (((4 * 3, 14 * pow(radius, 3)) / 3) * p);
}

Vector2D Circle ::position()
{
    return centre;
}

bool Circle ::operator==(IPhysObject &ob)
{
    return this->mass() == ob.mass();
}

bool Circle ::operator<(IPhysObject &ob)
{
    return this->mass() < ob.mass();
}

void Circle ::print()
{
    cout << "Triangle = " << '\n';
    cout << "Radius = " << radius << '\n';
    cout << "Density = " << p << '\n';
    cout << "Centre x = " << centre.x << " y = " << centre.y << '\n';
}

void Triangle ::initFromDialog()
{
    cout << "Enter your side = ";
    cin >> a;
    cout << "Enter your density = ";
    cin >> p;
    cout << "Enter your centre = ";
    cin >> centre.x >> centre.y;
}

const char *Triangle ::classname()
{
    return "Triangle";
}

unsigned int Triangle ::size()
{
    return sizeof(*this);
}

double Triangle ::square()
{
    return a * a * sqrt(3) * 0.25;
}

double Triangle ::perimeter()
{
    return 3 * (a);
}

double Triangle ::mass()
{
    return ((a * a * a * sqrt(2) / 12) * p);
}

Vector2D Triangle ::position()
{
    return centre;
}

bool Triangle ::operator==(IPhysObject &ob)
{
    return this->mass() == ob.mass();
}

bool Triangle ::operator<(IPhysObject &ob)
{
    return this->mass() < ob.mass();
}

void Triangle ::print()
{
    cout << "Triangle = " << '\n';
    cout << "side = " << a << '\n';
    cout << "Density = " << p << '\n';
    cout << "Centre x = " << centre.x << " y = " << centre.y << '\n';
}

void Universum ::AddCircle()
{
    Circle *circle = new Circle();
    circle->initFromDialog();
    something.push_back(circle);
    //something.push_back(circle);
}

void Universum ::AddTriangle()
{
    {
        Triangle *triangle = new Triangle();
        triangle->initFromDialog();
        something.push_back(triangle);
        //something.push_back(triangle);
    }
}

void Universum ::Show()
{
    if (something.empty())
    {
        cout << "Empty" << '\n';
    }
    else
    {
        for (int i = 0; i < something.size(); i++)
        {
            something[i]->print();
        }
    }
}

void Universum ::AllSquare()
{
    if (something.empty())
    {
        cout << "Empty" << '\n';
    }
    else
    {
        double result = 0;
        for (int i = 0; i < something.size(); i++)
        {
            result += something[i]->square();
        }
        cout << "Sum of all squares = " << result << '\n';
    }
}

void Universum ::AllPerimeter()
{
    if (something.empty())
    {
        cout << "Empty" << '\n';
    }
    else
    {
        double result = 0;
        for (int i = 0; i < something.size(); i++)
        {
            result += something[i]->perimeter();
        }
        cout << "Sum of all perimeters = " << result << '\n';
    }
}

void Universum ::Mass()
{
    if (something.empty())
    {
        cout << "Empty" << '\n';
    }
    else
    {
        double numerator = 0;
        double denominator = 0;
        for (int i = 0; i < something.size(); i++)
        {
            double x = something[i]->position().x;
            double y = something[i]->position().y;
            numerator += (something[i]->mass() * x * y);
            denominator += something[i]->mass();
        }
        cout << numerator / denominator << '\n';
    }
}

void Universum ::Memory()
{
    if (something.empty())
    {
        cout << "Empty" << '\n';
    }
    else
    {
        unsigned int result = 0;
        for (int i = 0; i < something.size(); i++)
        {
            result += something[i]->size();
        }
        cout << "Sum of all memory = " << result << '\n';
    }
}

void Universum ::Sort()
{
    if (something.empty())
    {
        cout << "Empty" << '\n';
    }
    else
    {
        for (int i = 1; i < something.size(); i++)
        {
            for (int j = i; j > 0 && something[j - 1]->mass() > something[j]->mass(); j--)
            {
                swap(something[j - 1], something[j]);
            }
        }
        for (int i = 0; i < something.size(); i++)
        {
            cout << something[i]->mass() << " ";
        }
    }
}