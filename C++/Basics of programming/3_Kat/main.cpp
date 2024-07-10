#include <iostream>
#include "Square.cpp"
using namespace std;

int main() {
    Square square1;
    square1.setSide(5);
    square1.setX(0);
    square1.setY(0);
    square1.setAngle(0);
    Square square2(2, 2, 5, 0);

    cout << "Yavniy" << "\n";
    cout << "square 1 == square 2: ";
    if(square1.operator==(square2)) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout << "\n";
    cout << "square 1 != square 2: ";
    if(square1.operator!=(square2)) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout << "\n";
    cout << "square 1 > square 2: ";
    if(square1.operator>(square2)) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout << "\n";
    cout << "square 1 < square 2: ";
    if(square1.operator<(square2)) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout << "\n";

    cout << "\n" << "Neyavniy" << "\n";
    cout << "square 1 == square 2: " ;
    if(square1 == square2) {
        cout << "true";
    }
    else{
        cout << "false" << "\n";
    }
    cout << "square 1 != square 2: " ;
    if(square1 != square2) {
        cout << "true";
    }
    else{
        cout << "false" << "\n";
    }
    cout << "square 1 > square 2: " ;
    if(square1 > square2) {
        cout << "true";
    }
    else{
        cout << "false" << "\n";
    }
    cout << "square 1 < square 2: " ;
    if(square1 < square2) {
        cout << "true";
    }
    else{
        cout << "false" << "\n";
    };

}