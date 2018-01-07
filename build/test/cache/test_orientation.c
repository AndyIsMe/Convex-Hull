#include "build/temp/_test_orientation.c"
#include "nodeverifier.h"
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

   ), (UNITY_UINT)(20), UNITY_DISPLAY_STYLE_INT);

}



void test_orientation_expect_clockwise(void)

{

  initN(&pointPv12,0,0);

  initN(&pointPv15,2,8);

  initN(&pointTaruc,8,2);



    int i = orientation(pointPv12,pointPv15,pointTaruc);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);

}



void test_orientation_expect_colinear(void)

{

  initN(&pointPv12,0,0);

  initN(&pointPv15,0,0);

  initN(&pointTaruc,0,0);



    int i = orientation(pointPv12,pointPv15,pointTaruc);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(40), UNITY_DISPLAY_STYLE_INT);

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

    Point *end = (convexHull(start , n , 1));



    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((n)), (

   ((void *)0)

   ), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

    testAssertEqualNode(0,0,"Genting Klang",end,57);

    testAssertEqualNode(0,3,"PV12",end+1,58);

    testAssertEqualNode(3,3,"WangsaMaju",end+2,59);

    testAssertEqualNode(3,0,"Block D",end+3,60);

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

    Point *end = (convexHull(start , n , 0));

    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((n)), (

   ((void *)0)

   ), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_INT);

    testAssertEqualNode(0,0,"Genting Klang",end,76);

    testAssertEqualNode(3,0,"Block D",end+1,77);

    testAssertEqualNode(3,3,"WangsaMaju",end+2,78);

    testAssertEqualNode(1,3,"PV12",end+3,79);





}



void test_6_random_coordinates_expect_no_shape_formed(void)

{

    initN(&pointPv12,0,3);

    initN(&pointPv15,2,2);

    Point start[]={pointPv12,pointPv15};



    int n = (sizeof(start))/(sizeof(start[0]));

    Point *end = (convexHull(start , n , 1));



    UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((n)), (

   ((void *)0)

   ), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_INT);

    testAssertEqualNode(0,3,"PV12",end,94);





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

    Point *end = (convexHull(start , n , 0));

    UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((n)), (

   ((void *)0)

   ), (UNITY_UINT)(114), UNITY_DISPLAY_STYLE_INT);

    testAssertEqualNode(-2,1,"PV12",end,115);

    testAssertEqualNode(-1,-4,"Block B",end+1,116);

    testAssertEqualNode(8,-3,"Block A",end+2,117);

    testAssertEqualNode(8,3,"TARUC",end+3,118);

    testAssertEqualNode(8,5,"Genting Klang",end+4,119);

}
