#include "square.h"
Square::Square(double x, double y, double side, double angle) : x(x), y(y), side(side), angle(angle) {}
Square::Square() : x(0), y(0), side(0), angle(0) {}

double Square::getX() const {
    return x;
}

void Square::setX(double x) {
    this->x = x;
}

double Square::getY() const {
    return y;
}

void Square::setY(double y) {
    this->y = y;
}

double Square::getSide() const {
    return side;
}

void Square::setSide(double side) {
    this->side = side;
}

double Square::getAngle() const {
    return angle;
}

void Square::setAngle(double angle) {
    this->angle = angle;
}

bool Square::operator==(const Square& other) const {
    return (this->side * this->side) == (other.side * other.side);
}

bool Square::operator!=(const Square& other) const {
    return !(*this == other);
}

bool Square::operator>(const Square& other) const {
    return (this->side * this->side) > (other.side * other.side);
}

bool Square::operator<(const Square& other) const {
    return (this->side * this->side) < (other.side * other.side);
}