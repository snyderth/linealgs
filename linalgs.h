#pragma once
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string.h>
using namespace std;


typedef struct point_s{
    float x, y;
} Point;

int close_to(vector<Point> spline, Point pnt);