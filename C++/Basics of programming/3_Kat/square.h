#pragma once
class Square {
private:
    double side;

public:
    Square(double x, double y, double side, double angle);
    Square();

    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);
    double getSide() const;
    void setSide(double side);
    double getAngle() const;
    void setAngle(double angle);

    bool operator==(const Square& other) const;
    bool operator!=(const Square& other) const;
    bool operator>(const Square& other) const;
    bool operator<(const Square& other) const;
};