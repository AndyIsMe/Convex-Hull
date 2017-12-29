#include "orientation.h"
#include <stdio.h>

//return 0 ---> colinear
//return 1 ---> clockwise
//return 2 ---> anticlockwise
int orientation(Point p,Point q,Point r)
{
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

  if(val > 0)
    return 1;
  else if(val < 0)
    return 2;
  else
    return 0;
}

void convexHull(Point points[] , int n)
{
  int i;
  int l = 0;
  int result = 0;
  int j;
  //Making sure that there must be at least 3 points
  if(n < 3)
  return ;

  //Search for the leftmost point
  for(i = 1 ; i < n ; i++)
  {
    if(points[l].x>points[i].x)
      l=i;
  }
  //Begin at the leftmost point
 //Keep joining points in anticlockwise direction
//until starting point
//This loop runs n times
//n = number of points user placed into it
  int p = l;
  int q;
  do {
    // Store current point to the result

    //for(result = 0 ; result< ;result++)
    points[result] = points[p];
    printf("result %d\n",result );
    printf("result[x] %d\n",points[result].x);
    printf("result[y] %d\n",points[result].y);

    // Search for a point q where a validation in function
    // orientation(p, x, q) is done and to be make sure that
    // it is counterclockwise for all points 'x'.
    // The idea is to keep track of last visited outermost point
    // during anticlockwise in q
    // If any point 'i' is the outermost point,
    // then update q.
    q = (p+1)%n;
    for(i = 0;i < n;i++)
      {
        if(orientation(points[p],points[i],points[q])==2)
          q = i;
      }
      // After valiation of point q as the outermost point in anticlockwise
      // Let p = q as for the next joining outermost point
      p = q;
      //printf("point[p] x %d\n",points[p].x);
      //printf("point[p] y %d\n",points[p].y);
  } while(p != l);
}
