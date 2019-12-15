#include "linalgs.h"


int close_to(vector<Point> spline, Point pnt){
    float minD = 200.0, currD = 0.0;
    int minInd = -1;

    for(int i = 0; i < spline.size(); i++){
        currD = sqrt(pow(spline[i].x - pnt.x, 2) + pow(spline[i].y - pnt.y, 2));
        if(minD > currD){
            minD = currD;
            minInd = i;
        }
    }

    return minInd;
}