#include "Point.h"

Point::Point() : x(0), y(0), angle(90) {}

void Point::setStartX(float startX) {
    x = startX;
}

void Point::setStartY(float startY) {
    y = startY;
}

void Point::setAngle(float ang) {
    angle = ang;
}

float Point::getStartX() const {
    return x;
}

float Point::getStartY() const {
    return y;
}

float Point::getAngle() const {
    return angle;
}
