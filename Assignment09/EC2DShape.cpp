#include <math.h>
#include "EC2DShape.h"
#include <iostream>

using namespace std;


// CLass EC2DShape methods
bool EC2DShape::IsIntersectShape(const EC2DShape &rhs) const {
    int rhs_xul, rhs_yul, rhs_xlr, rhs_ylr;
    rhs.GetBoundingBox(rhs_xul, rhs_yul, rhs_xlr, rhs_ylr);
    int my_xul, my_yul, my_xlr, my_ylr;
    GetBoundingBox(my_xul, my_yul, my_xlr, my_ylr);

    // Check verticle positions
    if (my_yul > rhs_ylr) return false;
    else if (my_ylr < rhs_yul) return false;
    // Check horizontal positions
    else if (my_xlr < rhs_xul) return false;
    else if (my_xul > rhs_xlr) return false;
    else return true;

}

bool EC2DShape::IsContaining(const EC2DShape &rhs) const {
    int rhs_xul, rhs_yul, rhs_xlr, rhs_ylr;
    rhs.GetBoundingBox(rhs_xul, rhs_yul, rhs_xlr, rhs_ylr);

    if (IsIntersect(rhs_xul, rhs_yul) && IsIntersect(rhs_xlr, rhs_ylr)) return true;
    else return false;
}

// CLass ECRectangle methods
ECRectangle::ECRectangle(int xUL, int yUL, int xLR, int yLR) {
    // TODO: Might want to try and do the more efficient method for initalization
    x_ul = xUL;
    y_ul = yUL;
    x_lr = xLR;
    y_lr = yLR;
}

void ECRectangle::GetBoundingBox(int &xUpperLeft,int &yUpperLeft,int &xLowerRight,int &yLowerRight) const {
    xUpperLeft = x_ul;
    yUpperLeft = y_ul;

    xLowerRight = x_lr;
    yLowerRight = y_lr;
}

bool ECRectangle::IsIntersect(int px, int py) const {
    if (px >= x_ul && px <= x_lr && py >= y_ul && py <= y_lr) return true;
    else return false;
}

ECCircle::ECCircle(int x, int y, int radius) : xp(x), yp(y), rad(radius) {}

void ECCircle::GetBoundingBox( int &xUpperLeft, int &yUpperLeft, int &xLowerRight, int &yLowerRight ) const {
    xUpperLeft = xp - rad;
    yUpperLeft = yp - rad;

    xLowerRight = xp + rad;
    yLowerRight = yp + rad;
}

bool ECCircle::IsIntersect(int px, int py) const {
    float distance = sqrt(pow(px - xp, 2) + pow(py - yp, 2));
    if (distance <= rad) return true;
    else return false;
}