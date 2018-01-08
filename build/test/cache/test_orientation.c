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

   ), (UNITY_UINT)(21), UNITY_DISPLAY_STYLE_INT);

}



void test_orientation_expect_clockwise(void)

{

  initN(&pointPv12,0,0);

  initN(&pointPv15,2,8);

  initN(&pointTaruc,8,2);



    int i = orientation(pointPv12,pointPv15,pointTaruc);

    UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(31), UNITY_DISPLAY_STYLE_INT);

}



void test_orientation_expect_colinear(void)

{

  initN(&pointPv12,0,0);

  initN(&pointPv15,0,0);

  initN(&pointTaruc,0,0);



    int i = orientation(pointPv12,pointPv15,pointTaruc);

    UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

}

void test_6_random_coordinates_after_Jarvis_algorithm_expect_starting_Pv12_clockwise_ending_BlockD(void)

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

   ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_INT);

    testAssertEqualNode(0,0,"Genting Klang",end,78);

    testAssertEqualNode(0,3,"PV12",end+1,79);

    testAssertEqualNode(3,3,"Wangsa Maju",end+2,80);

    testAssertEqualNode(3,0,"Block D",end+3,81);



    free(end);

}

void test_6_random_coordinates_after_Jarvis_algorithm_expect_starting_Genting_Klang_anticlockwise_ending_PV12(void)

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

   ), (UNITY_UINT)(117), UNITY_DISPLAY_STYLE_INT);

    testAssertEqualNode(0,0,"Genting Klang",end,118);

    testAssertEqualNode(3,0,"Block D",end+1,119);

    testAssertEqualNode(3,3,"Wangsa Maju",end+2,120);

    testAssertEqualNode(1,3,"PV12",end+3,121);



    free(end);

}

void test_8_random_coordinates_after_Jarvis_algorithm_expect_starting_Pv12_anticlockwise_ending_Genting_Klang(void)

{

    initN(&pointPv12,-2,1);

    initN(&pointPv15,2,1);

    initN(&pointTaruc,8,3);

    initN(&pointBlockD,4,2);

    initN(&pointGK,8,5);

    initN(&pointWangsa,4,-1);

    initN(&pointKajang,8,-3);

    initN(&pointCheras,-1,-4);



    Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa,pointKajang,pointCheras};



    int n = (sizeof(start))/(sizeof(start[0]));

    Point *end = (convexHull(start , n , 0));

    UnityAssertEqualNumber((UNITY_INT)((8)), (UNITY_INT)((n)), (

   ((void *)0)

   ), (UNITY_UINT)(160), UNITY_DISPLAY_STYLE_INT);

    testAssertEqualNode(-2,1,"PV12",end,161);

    testAssertEqualNode(-1,-4,"Cheras",end+1,162);

    testAssertEqualNode(8,-3,"Kajang",end+2,163);

    testAssertEqualNode(8,3,"TARUC",end+3,164);

    testAssertEqualNode(8,5,"Genting Klang",end+4,165);



    free(end);

}

void test_10_random_coordinates_after_Jarvis_algorithm_expect_starting_BlockD_clockwise_ending_Pv12(void)

{

    initN(&pointPv12,90,141);

    initN(&pointPv15,95,243);

    initN(&pointTaruc,158,153);

    initN(&pointBlockD,50,197);

    initN(&pointGK,90,192);

    initN(&pointWangsa,161,214);

    initN(&pointKajang,133,202);

    initN(&pointCheras,124,183);

    initN(&pointTamanMelawati,112,170);

    initN(&pointGombak,105,210);





    Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa

                  ,pointKajang,pointCheras,pointTamanMelawati,pointGombak};



    int n = (sizeof(start))/(sizeof(start[0]));

    Point *end = (convexHull(start , n , 1));

    UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((n)), (

   ((void *)0)

   ), (UNITY_UINT)(208), UNITY_DISPLAY_STYLE_INT);

    testAssertEqualNode(50,197,"Block D",end,209);

    testAssertEqualNode(95,243,"PV15",end+1,210);

    testAssertEqualNode(161,214,"Wangsa Maju",end+2,211);

    testAssertEqualNode(158,153,"TARUC",end+3,212);

    testAssertEqualNode(90,141,"PV12",end+4,213);



    free(end);

}

void test_13_random_coordinates_after_Jarvis_algorithm_expect_starting_MJ_clockwise_ending_TM(void)

{

    initN(&pointPv12,90,141);

    initN(&pointPv15,80,180);

    initN(&pointTaruc,158,153);

    initN(&pointBlockD,56,253);

    initN(&pointGK,156,255);

    initN(&pointWangsa,28,196);

    initN(&pointKajang,197,199);

    initN(&pointCheras,119,275);

    initN(&pointTamanMelawati,116,111);

    initN(&pointGombak,110,117);

    initN(&pointAmpangPark,181,274);

    initN(&pointMasjidJamek,20,117);

    initN(&pointKLCC,177,141);





    Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa

                  ,pointKajang,pointCheras,pointTamanMelawati,pointGombak

                  ,pointAmpangPark,pointMasjidJamek,pointKLCC};



    int n = (sizeof(start))/(sizeof(start[0]));

    Point *end = (convexHull(start , n , 1));

    UnityAssertEqualNumber((UNITY_INT)((13)), (UNITY_INT)((n)), (

   ((void *)0)

   ), (UNITY_UINT)(268), UNITY_DISPLAY_STYLE_INT);

    testAssertEqualNode(20,117,"Masjid Jamek",end,269);

    testAssertEqualNode(28,196,"Wangsa Maju",end+1,270);

    testAssertEqualNode(56,253,"Block D",end+2,271);

    testAssertEqualNode(119,275,"Cheras",end+3,272);

    testAssertEqualNode(181,274,"Ampang Park",end+4,273);

    testAssertEqualNode(197,199,"Kajang",end+5,274);

    testAssertEqualNode(177,141,"KLCC",end+6,275);

    testAssertEqualNode(116,111,"Taman Melawati",end+7,276);



    free(end);

}

void test_13_random_coordinates_after_Jarvis_algorithm_expect_starting_MJ_anticlockwise_ending_WM(void)

{

    initN(&pointPv12,90,141);

    initN(&pointPv15,80,180);

    initN(&pointTaruc,158,153);

    initN(&pointBlockD,56,253);

    initN(&pointGK,156,255);

    initN(&pointWangsa,28,196);

    initN(&pointKajang,197,199);

    initN(&pointCheras,119,275);

    initN(&pointTamanMelawati,116,111);

    initN(&pointGombak,110,117);

    initN(&pointAmpangPark,181,274);

    initN(&pointMasjidJamek,20,117);

    initN(&pointKLCC,177,141);





    Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa

                  ,pointKajang,pointCheras,pointTamanMelawati,pointGombak

                  ,pointAmpangPark,pointMasjidJamek,pointKLCC};



    int n = (sizeof(start))/(sizeof(start[0]));

    Point *end = (convexHull(start , n , 0));

    UnityAssertEqualNumber((UNITY_INT)((13)), (UNITY_INT)((n)), (

   ((void *)0)

   ), (UNITY_UINT)(318), UNITY_DISPLAY_STYLE_INT);

    testAssertEqualNode(20,117,"Masjid Jamek",end,319);

    testAssertEqualNode(116,111,"Taman Melawati",end+1,320);

    testAssertEqualNode(177,141,"KLCC",end+2,321);

    testAssertEqualNode(197,199,"Kajang",end+3,322);

    testAssertEqualNode(181,274,"Ampang Park",end+4,323);

    testAssertEqualNode(119,275,"Cheras",end+5,324);

    testAssertEqualNode(56,253,"Block D",end+6,325);

    testAssertEqualNode(28,196,"Wangsa Maju",end+7,326);



    free(end);

}

void test_30_random_coordinates_after_Jarvis_algorithm_expect_starting_MJ_anticlockwise_ending_WM(void)

{

    initN(&pointPv12,90,141);

    initN(&pointPv15,96,206);

    initN(&pointTaruc,90,153);

    initN(&pointBlockD,56,253);

    initN(&pointGK,105,166);

    initN(&pointWangsa,31,196);

    initN(&pointKajang,197,199);

    initN(&pointCheras,119,275);

    initN(&pointTamanMelawati,116,111);

    initN(&pointGombak,144,172);

    initN(&pointAmpangPark,181,274);

    initN(&pointMasjidJamek,20,117);

    initN(&pointKLCC,177,141);

    initN(&pointSriRampai,62,240);

    initN(&pointSetiawangsa,105,248);

    initN(&pointJelatek,144,233);

    initN(&pointDK,130,206);

    initN(&pointDamai,163,173);

    initN(&pointKB,148,155);

    initN(&pointPS,121,131);

    initN(&pointKLS,107,118);

    initN(&pointBangsar,95,117);

    initN(&pointAH,72,122);

    initN(&pointKerinchi,31,119);

    initN(&pointUniversiti,38,191);

    initN(&pointTJ,75,163);

    initN(&pointAJ,60,144);

    initN(&pointTP,76,128);

    initN(&pointTB,116,140);

    initN(&pointKJ,144,172);





    Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa

                  ,pointKajang,pointCheras,pointTamanMelawati,pointGombak

                  ,pointAmpangPark,pointMasjidJamek,pointKLCC,pointMasjidJamek

                  ,pointSriRampai,pointSetiawangsa,pointJelatek,pointDK,pointDamai

                  ,pointKB,pointPS,pointKLS,pointBangsar,pointAH,pointKerinchi

                  ,pointUniversiti,pointTJ,pointAJ,pointTP,pointTB};



    int n = (sizeof(start))/(sizeof(start[0]));

    Point *end = (convexHull(start , n , 0));

    UnityAssertEqualNumber((UNITY_INT)((30)), (UNITY_INT)((n)), (

   ((void *)0)

   ), (UNITY_UINT)(405), UNITY_DISPLAY_STYLE_INT);

    testAssertEqualNode(20,117,"Masjid Jamek",end,406);

    testAssertEqualNode(116,111,"Taman Melawati",end+1,407);

    testAssertEqualNode(177,141,"KLCC",end+2,408);

    testAssertEqualNode(197,199,"Kajang",end+3,409);

    testAssertEqualNode(181,274,"Ampang Park",end+4,410);

    testAssertEqualNode(119,275,"Cheras",end+5,411);

    testAssertEqualNode(56,253,"Block D",end+6,412);

    testAssertEqualNode(31,196,"Wangsa Maju",end+7,413);



    free(end);

}



void test_5_random_coordinates_after_Jarvis_algorithm_expect_starting_Pv12_clockwise_ending_BlockD(void)

{

    initN(&pointPv12,0,3);

    initN(&pointPv15,2,2);

    initN(&pointTaruc,1,1);

    initN(&pointBlockD,3,0);

    initN(&pointGK,0,0);

    initN(&pointWangsa,110,110);

    Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa};



    int n = (sizeof(start))/(sizeof(start[0]));

    Point *end = (convexHull(start , n , 1));



    UnityAssertEqualNumber((UNITY_INT)((6)), (UNITY_INT)((n)), (

   ((void *)0)

   ), (UNITY_UINT)(431), UNITY_DISPLAY_STYLE_INT);

    testAssertEqualNode(0,0,"Genting Klang",end,432);

    testAssertEqualNode(0,3,"PV12",end+1,433);

    testAssertEqualNode(110,110,"Wangsa Maju",end+2,434);

    testAssertEqualNode(3,0,"Block D",end+3,435);



    free(end);

}
