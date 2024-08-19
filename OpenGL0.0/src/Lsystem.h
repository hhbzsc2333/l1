#ifndef LSYSTEM_H
#define LSYSTEM_H

#include <string>
#include <stack>
#include "Point.h"

//std::string combineLine(int iteration, std::string axioms, std::string rule1, std::string rule2);
std::string combineLine(int iteration, const std::string& initialp, const std::string& rule1, const std::string& rule2);
std::stack<Point> getStack(const std::string& list, float angle, float lineLength);
void drawLSystem(const std::stack<Point>& points, float lineLength, float* color);

#endif // LSYSTEM_H

