#include "build/temp/_test_orientation.c"
#include "orientation.h"
#include "unity.h"


void setUp(void){}

void tearDown(void){}



void test_orientation_expect_anticlockwise(void)

{

    Point p1 = {0,0};

    Point p2 = {4,4};

    Point p3 = {1,2};



    int i = orientation(p1,p2,p3);

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(14), UNITY_DISPLAY_STYLE_INT);

}



void test_orientation_expect_clockwise(void)

{

    Point p1 = {0,0};

    Point p2 = {2,8};

    Point p3 = {8,2};



    int i = orientation(p1,p2,p3);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

}



void test_orientation_expect_colinear(void)

{

    Point p1 = {0,0};

    Point p2 = {0,0};

    Point p3 = {0,0};



    int i = orientation(p1,p2,p3);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);

}

void xtest_orientation1(void)

{

    Point points[] = {{1,3},{2,2},{1,1},{3,0},{0,0},{3,3}};



    int n = (sizeof(points))/(sizeof(points[0]));

    convexHull(points , n , 0);

    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((n)), (

   ((void *)0)

   ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_INT);





}



void test_orientation2(void)

{

    Point points[] = {{-2,1},{2,1},{8,3},{4,2},{8,5},{4,-1},{8,-3},{-1,-4}};



    int n = (sizeof(points))/(sizeof(points[0]));

    convexHull(points , n , 1);

    UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((n)), (

   ((void *)0)

   ), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_INT);





}
