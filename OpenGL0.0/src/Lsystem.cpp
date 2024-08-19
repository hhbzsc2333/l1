#include "LSystem.h"
#include <GL/glew.h>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


std::string combineLine(int iteration, const std::string& initialp, const std::string& rule1, const std::string& rule2)
{
    std::string list = initialp;
    for (int n = 0; n < iteration; n++) {
        std::string newProducts;
        for (char current : list) {
            if (current == rule1[0]) {
                newProducts += rule1.substr(2);
            }
            else if (current == rule2[0]) {
                newProducts += rule2.substr(2);
            }
            else {
                newProducts += current;
            }
        }
        list = newProducts;
    }
    return list;
}

std::stack<Point> getStack(const std::string& list, float angle, float lineLength)
{
    std::stack<Point> st;
    std::stack<Point> saveStack;
    Point currentPoint;
    currentPoint.setStartX(0.0);
    currentPoint.setStartY(-1.0);
    currentPoint.setAngle(90.0);

   

    for (char letter : list) {
        if (letter == 'F') {
            float newX = currentPoint.getStartX() + lineLength * cos(currentPoint.getAngle() * M_PI / 180.0);
            float newY = currentPoint.getStartY() + lineLength * sin(currentPoint.getAngle() * M_PI / 180.0);

            Point newPoint;
            newPoint.setStartX(newX);
            newPoint.setStartY(newY);
            newPoint.setAngle(currentPoint.getAngle());

            st.push(currentPoint);
            currentPoint = newPoint;
        }
        else if (letter == 'f') {
            float newX = currentPoint.getStartX() + lineLength * cos(currentPoint.getAngle() * M_PI / 180.0);
            float newY = currentPoint.getStartY() + lineLength * sin(currentPoint.getAngle() * M_PI / 180.0);

            currentPoint.setStartX(newX);
            currentPoint.setStartY(newY);
        }
        else if (letter == '+') {
            currentPoint.setAngle(currentPoint.getAngle() - angle);
        }
        else if (letter == '-') {
            currentPoint.setAngle(currentPoint.getAngle() + angle);
        }
        else if (letter == '[') {
            saveStack.push(currentPoint);
        }
        else if (letter == ']') {
            if (!saveStack.empty()) {
                currentPoint = saveStack.top();
                saveStack.pop();
            }
        }
    }
    st.push(currentPoint);
    return st;

}

void drawLSystem(const std::stack<Point>& points, float lineLength, float* color)
{
    std::stack<Point> localPoints = points;
    glClear(GL_COLOR_BUFFER_BIT);
    //glColor3f(0.0, 1.0, 0.0);
    glColor3f(color[0], color[1], color[2]);

    glBegin(GL_LINES);
    Point previousPoint = localPoints.top();
    localPoints.pop();

    while (!localPoints.empty()) {
        Point p = localPoints.top();
        localPoints.pop();

        glVertex2f(previousPoint.getStartX(), previousPoint.getStartY());
        glVertex2f(p.getStartX(), p.getStartY());

        previousPoint = p;
    }
    glEnd();
}
