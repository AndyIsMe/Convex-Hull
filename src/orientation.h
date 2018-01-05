#ifndef _ORIENTATION_H
#define _ORIENTATION_H

#define clockwise 1
#define anticlockwise 0
#define collinear 0

typedef struct Point Point;
struct Point
{
  int x,y;
  char *place;
  double data;
};

int orientation(Point p,Point q,Point r);
Point *convexHull(Point points[] , int n , int choice);
#endif // _ORIENTATION_H
