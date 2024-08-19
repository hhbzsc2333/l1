#ifndef POINT_H
#define POINT_H

class Point {
public:
    float x, y, angle;

    Point();
    void setStartX(float startX);
    void setStartY(float startY);
    void setAngle(float ang);
    float getStartX() const;
    float getStartY() const;
    float getAngle() const;
};

#endif // POINT_H
