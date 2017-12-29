#ifndef _ORIENTATION_H
#define _ORIENTATION_H

typedef struct Point Point;
struct Point
{
  int x,y;
};

int orientation(Point p1,Point p2,Point p3);
void convexHull(Point points[] , int n);
#endif // _ORIENTATION_H
