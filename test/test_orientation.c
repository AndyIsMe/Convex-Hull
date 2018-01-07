#include "unity.h"
#include "orientation.h"
#include "nodehelper.h"
#include "nodeverifier.h"
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

void test_6_random_coordinates_expect_starting_Pv12_Jarvis_clockwise_ending_BlockD(void)
{
    initN(&pointPv12,0,3);
    initN(&pointPv15,2,2);
    initN(&pointTaruc,1,1);
    initN(&pointBlockD,3,0);
    initN(&pointGK,0,0);
    initN(&pointWangsa,3,3);
    Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa};

    int n = (sizeof(start))/(sizeof(start[0]));
    Point *end = (convexHull(start , n , clockwise));

    TEST_ASSERT_EQUAL(6,n);
    TEST_ASSERT_EQUAL_POINT(0,0,"Genting Klang",end);
    TEST_ASSERT_EQUAL_POINT(0,3,"PV12",end+1);
    TEST_ASSERT_EQUAL_POINT(3,3,"WangsaMaju",end+2);
    TEST_ASSERT_EQUAL_POINT(3,0,"Block D",end+3);
}

void test_6_random_coordinates_expect_starting_Genting_Klang_Jarvis_anticlockwise_ending_PV12(void)
{
    initN(&pointPv12,1,3);
    initN(&pointPv15,2,2);
    initN(&pointTaruc,1,1);
    initN(&pointBlockD,3,0);
    initN(&pointGK,0,0);
    initN(&pointWangsa,3,3);
    Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa};

    int n = (sizeof(start))/(sizeof(start[0]));
    Point *end = (convexHull(start , n , anticlockwise));
    TEST_ASSERT_EQUAL(6,n);
    TEST_ASSERT_EQUAL_POINT(0,0,"Genting Klang",end);
    TEST_ASSERT_EQUAL_POINT(3,0,"Block D",end+1);
    TEST_ASSERT_EQUAL_POINT(3,3,"WangsaMaju",end+2);
    TEST_ASSERT_EQUAL_POINT(1,3,"PV12",end+3);


}

void test_6_random_coordinates_expect_no_shape_formed(void)
{
    initN(&pointPv12,0,3);
    initN(&pointPv15,2,2);
    Point start[]={pointPv12,pointPv15};

    int n = (sizeof(start))/(sizeof(start[0]));
    Point *end = (convexHull(start , n , clockwise));

    TEST_ASSERT_EQUAL(2,n);
    //TEST_ASSERT_EQUAL_POINT(0,3,"PV12",end);
    //TEST_ASSERT_EQUAL_POINT(2,2,"PV15",end+1);

}

void test_8_random_coordinates_expect_starting_Pv12_Jarvis_anticlockwise_ending_Genting_Klang(void)
{
    initN(&pointPv12,-2,1);
    initN(&pointPv15,2,1);
    initN(&pointTaruc,8,3);
    initN(&pointBlockD,4,2);
    initN(&pointGK,8,5);
    initN(&pointWangsa,4,-1);
    initN(&pointBlockA,8,-3);
    initN(&pointBlockB,-1,-4);

    Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa,pointBlockA,pointBlockB};

    int n = (sizeof(start))/(sizeof(start[0]));
    Point *end = (convexHull(start , n , anticlockwise));
    TEST_ASSERT_EQUAL(8,n);
    TEST_ASSERT_EQUAL_POINT(-2,1,"PV12",end);
    TEST_ASSERT_EQUAL_POINT(-1,-4,"Block B",end+1);
    TEST_ASSERT_EQUAL_POINT(8,-3,"Block A",end+2);
    TEST_ASSERT_EQUAL_POINT(8,3,"TARUC",end+3);
    TEST_ASSERT_EQUAL_POINT(8,5,"Genting Klang",end+4);
}
