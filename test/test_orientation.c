#include "unity.h"
#include "orientation.h"

void setUp(void){}
void tearDown(void){}

void test_orientation_expect_anticlockwise(void)
{
    Point p1 = {0,0};
    Point p2 = {4,4};
    Point p3 = {1,2};

    int i = orientation(p1,p2,p3);
    TEST_ASSERT_EQUAL(2,i);
}

void test_orientation_expect_clockwise(void)
{
    Point p1 = {0,0};
    Point p2 = {2,8};
    Point p3 = {8,2};

    int i = orientation(p1,p2,p3);
    TEST_ASSERT_EQUAL(1,i);
}

void test_orientation_expect_colinear(void)
{
    Point p1 = {0,0};
    Point p2 = {0,0};
    Point p3 = {0,0};

    int i = orientation(p1,p2,p3);
    TEST_ASSERT_EQUAL(0,i);
}
/*
void test_orientation(void)
{
    Point points[] = {{0,3},{2,2},{1,1},{3,0},{0,0},{3,3}};

    int n = (sizeof(points))/(sizeof(points[0]));
    convexHull(points , n);
    TEST_ASSERT_EQUAL(6,n);
    TEST_ASSERT_EQUAL(3,points[5].y);
    //TEST_ASSERT_EQUAL(0,i);
}*/

void xtest_orientation1(void)
{
    Point points[] = {{1,3},{2,2},{1,1},{3,0},{0,0},{3,3}};

    int n = (sizeof(points))/(sizeof(points[0]));
    convexHull(points , n , anticlockwise);
    TEST_ASSERT_EQUAL(6,n);
    //TEST_ASSERT_EQUAL(3,points[5].y);
    //TEST_ASSERT_EQUAL(0,i);
}

void test_orientation2(void)
{
    Point points[] = {{-2,1},{2,1},{8,3},{4,2},{8,5},{4,-1},{8,-3},{-1,-4}};

    int n = (sizeof(points))/(sizeof(points[0]));
    convexHull(points , n , clockwise);
    TEST_ASSERT_EQUAL(8,n);
    //TEST_ASSERT_EQUAL(3,points[5].y);
    //TEST_ASSERT_EQUAL(0,i);
}
