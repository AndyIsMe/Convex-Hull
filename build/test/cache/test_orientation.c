#include "build/temp/_test_orientation.c"
#include "nodehelper.h"
#include "orientation.h"
#include "unity.h"




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

    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_INT);

}



void test_orientation_expect_clockwise(void)

{

  initN(&pointPv12,0,0);

  initN(&pointPv15,2,8);

  initN(&pointTaruc,8,2);



    int i = orientation(pointPv12,pointPv15,pointTaruc);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);

}



void test_orientation_expect_colinear(void)

{

  initN(&pointPv12,0,0);

  initN(&pointPv15,0,0);

  initN(&pointTaruc,0,0);



    int i = orientation(pointPv12,pointPv15,pointTaruc);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);

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





    int n = (sizeof(start))/(sizeof(start[0]));



    Point *end = (convexHull(start , n , 1));



    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((n)), (

   ((void *)0)

   ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);



    int x=(end)->x;

    UnityAssertEqualString((const char*)(("GentingKlang")), (const char*)(((end+1)->place)), (

   ((void *)0)

   ), (UNITY_UINT)(61));





}
