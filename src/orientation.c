#include "orientation.h"
#include <stdio.h>


/*int distance(Point p , Point q,Point r)
{
  int val = sqrt((q.x-p.x)*(q.x-p.x)+(q.y-p.y)*(q.y-p.y));
  return val;
}*/


//return 0 ---> collinear
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

Point *convexHull(Point points[] , int n , int choice)
{
  double x , y;
  int i;
  int l = 0;
  //int result = 0;
  Point result[1001];
  int j;
  //Making sure that there must be at least 3 points
  //if(n < 3)
  //return ;

  //Search for the leftmost point
  for(i = 1 ; i < n ; i++)
  {
    if(points[l].x>points[i].x)
      l = i;
    else if((points[l].x==points[i].x)&&(points[l].y>points[i].y))
    l = i;
  }
  //Begin at the leftmost point
 //Keep joining points in anticlockwise direction
//until starting point
//This loop runs n times
//n = number of points user placed into it
  int p = l;
  int q;
  int count = 0;
  if(n<3)
  {
    for(i=0;i<n-1;i++)
    {
      //points[i]
    }
  }
  else
  {
  do {
    // Store current point to the result
    result[count] = points[p];
    points[p].data = p;
    //printf("p[x] %d\n",points[p].x);
    //printf("p[y] %d\n",points[p].y);
    //printf("place %s\n",points[p].place);
    printf("count %d\n",count);
    printf("[x] %d\n",result[count].x);
    printf("[y] %d\n",result[count].y);
    printf("place %s\n",result[count].place);
    count++;


    // Search for a point q where a validation in function
    //p = current point
    //q = next targer point
    // orientation(p, x, q) is done and to be make sure that
    // it is counterclockwise for all points 'x'.
    // The idea is to keep track of last visited outermost point
    // during anticlockwise in q
    // If any point 'i' is the outermost point,
    // then update q.
    q = (p+1)%n;
    for(i = 0;i < n;i++)
      {
        if(choice == 1){
          if(orientation(points[p],points[i],points[q])==1)
          q = i;
        }
        else if(choice == 0){
          if(orientation(points[p],points[i],points[q])==2)
          q = i;
        }
      }
      // After valiation of point q as the outermost point in anticlockwise
      // Let p = q as for the next joining outermost point
      p = q;
  } while(p != l);
  int z = &(result[0]);
  int z1 = &(result[1]);
  printf("z1 %d\n",z1 );
  printf("z %d\n",z );
  return z;
}
}

/*
void convexHull(Point points[] , int n , int choice)
{
  double x , y;
  int i;
  int l = 0;
  //int result = 0;
  Point result[100];
  int j;
  //Making sure that there must be at least 3 points
  //if(n < 3)
  //return ;

  //Search for the leftmost point
  for(i = 1 ; i < n ; i++)
  {
    if(points[l].x>points[i].x)
      l=i;
    else if((points[l].x==points[i].x)&&(points[l].y>points[i].y))
    l =i;
  }
  //Begin at the leftmost point
 //Keep joining points in anticlockwise direction
//until starting point
//This loop runs n times
//n = number of points user placed into it
  int p = l;
  int q;
  int count =0;
  if(n<3)
  {
    for(i=0;i<n-1;i++)
    {
      //points[i]
    }
  }
  else
  {
  do {
    // Store current point to the result
    printf("result %d\n",p );
    printf("result[x] %d\n",points[p].x);
    printf("result[y] %d\n",points[p].y);


    // Search for a point q where a validation in function
    //p = current point
    //q = next targer point
    // orientation(p, x, q) is done and to be make sure that
    // it is counterclockwise for all points 'x'.
    // The idea is to keep track of last visited outermost point
    // during anticlockwise in q
    // If any point 'i' is the outermost point,
    // then update q.
    q = (p+1)%n;
    for(i = 0;i < n;i++)
      {
        if(choice == 1){
          if(orientation(points[p],points[i],points[q])==1)
          q = i;
        }
        else if(choice == 0){
          if(orientation(points[p],points[i],points[q])==2)
          q = i;
        }
      }
      // After valiation of point q as the outermost point in anticlockwise
      // Let p = q as for the next joining outermost point
      p = q;
      //printf("point[p] x %d\n",points[p].x);
      //printf("point[p] y %d\n",points[p].y);
  } while(p != l);
}
}*/
