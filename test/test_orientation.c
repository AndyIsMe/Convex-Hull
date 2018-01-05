#include "unity.h"
#include "orientation.h"
#include "nodehelper.h"
#include <stdio.h>

void setUp(void)
{
    initNnode();
}
void tearDown(void){}

void test_orientation_expect_anticlockwise(void)
{
  initN(&pointPv12,0,0);
  initN(&pointPv15,4,4);
  initN(&pointTaruc,1,2);

    int i = orientation(pointPv12,pointPv15,pointTaruc);
    TEST_ASSERT_EQUAL(2,i);
}

void test_orientation_expect_clockwise(void)
{
  initN(&pointPv12,0,0);
  initN(&pointPv15,2,8);
  initN(&pointTaruc,8,2);

    int i = orientation(pointPv12,pointPv15,pointTaruc);
    TEST_ASSERT_EQUAL(1,i);
}

void test_orientation_expect_colinear(void)
{
  initN(&pointPv12,0,0);
  initN(&pointPv15,0,0);
  initN(&pointTaruc,0,0);

    int i = orientation(pointPv12,pointPv15,pointTaruc);
    TEST_ASSERT_EQUAL(0,i);
}

void test_orientation(void)
{
  int i;
    initN(&pointPv12,0,3);
    initN(&pointPv15,2,2);
    initN(&pointTaruc,1,1);
    initN(&pointBlockD,3,0);
    initN(&pointGK,0,0);
    initN(&pointWangsa,3,3);
    Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa};
    //Point *points[] = {{0,3},{2,2},{1,1},{3,0},{0,0},{3,3}};

    int n = (sizeof(start))/(sizeof(start[0]));
    //int end = (convexHull(start , n , clockwise));
    Point *end = (convexHull(start , n , clockwise));

    TEST_ASSERT_EQUAL(6,n);
    //TEST_ASSERT_EQUAL(4,end.data);
    int x=(end)->x;
    TEST_ASSERT_EQUAL_STRING("GentingKlang",(end+1)->place);
    //TEST_ASSERT_EQUAL(0,&points[4]->y);
    //TEST_ASSERT_EQUAL(0,i);
}
/*
void xtest_orientation1(void)
{
    Point points[] = {{1,3},{2,2},{1,1},{3,0},{0,0},{3,3}};

    int n = (sizeof(points))/(sizeof(points[0]));
    convexHull(points , n , clockwise);
    TEST_ASSERT_EQUAL(6,n);
    //TEST_ASSERT_EQUAL(3,points[5].y);
    //TEST_ASSERT_EQUAL(0,i);
}

void test_orientation2(void)
{
    Point points[] = {{-2,1},{2,1},{8,3},{4,2},{8,5},{4,-1},{8,-3},{-1,-4}};

    int n = (sizeof(points))/(sizeof(points[0]));
    convexHull(points , n , anticlockwise);
    TEST_ASSERT_EQUAL(8,n);
    //TEST_ASSERT_EQUAL(3,points[5].y);
    //TEST_ASSERT_EQUAL(0,i);
}*/
