#include "unity.h"
#include "orientation.h"
#include "nodehelper.h"
#include "nodeverifier.h"
#include <stdio.h>
#include <stdlib.h>

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

/** (PV12)      (PV15)      (TARUC)       (Block D)     (Genting Klang)   (Wangsa Maju)  } 6 Random Coordinates
  *    .(0,3)     .(2,2)       .(1,1)         .(3,0)            .(0,0)          .(3,3)   } Search for the left most point
  *
  *  Found left most point(Genting Klang) and undergo Convex Hull through Jarvis March Algorithm in clockwise direction
  *        (Genting Klang)     (PV12)              (Genting Klang)       (PV12)    (Wangsa Maju)            ____
  *               .---------------.       -->             .----------------.-----------.                       |
  *                                                                                                            |
  *                                         (Genting Klang)     (PV12)      (Wangsa Maju)     (Block D)     <_|
  *                                                 .--------------.---------------.---------------.
  *
  *
  *                                Other coordinates are enclosed inside the shape formed from the Convex Hull Algorithm
  *
  *
  *
  *
  *
**/


void test_6_random_coordinates_after_Jarvis_algorithm_expect_starting_Genting_Klang_clockwise_ending_BlockD(void)
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
    TEST_ASSERT_EQUAL_POINT(3,3,"Wangsa Maju",end+2);
    TEST_ASSERT_EQUAL_POINT(3,0,"Block D",end+3);

    free(end);
}

/** (PV12)      (PV15)      (TARUC)       (Block D)     (Genting Klang)   (Wangsa Maju)  } 6 Random Coordinates
  *    .(1,3)     .(2,2)       .(1,1)         .(3,0)            .(0,0)          .(3,3)   } Search for the left most point
  *
  *  Found left most point(Genting Klang) and undergo Convex Hull through Jarvis March Algorithm in anticlockwise direction
  *        (Genting Klang)     (Block D)            (Genting Klang)       (Block D)    (Wangsa Maju)            ____
  *               .-----------------.       -->             .------------------.-------------.                     |
  *                                                                                                                |
  *                                         (Genting Klang)     (Block D)      (Wangsa Maju)     (Pv12)          <_|
  *                                                 .----------------.---------------.-------------.
  *                                     Other coordinates are enclosed inside the shape formed from the Convex Hull Algorithm
  *
  *
  *
  *
  *
  *
  *
**/

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
    Point *end = (convexHull(start , n , anticlockwise));
    TEST_ASSERT_EQUAL(6,n);
    TEST_ASSERT_EQUAL_POINT(0,0,"Genting Klang",end);
    TEST_ASSERT_EQUAL_POINT(3,0,"Block D",end+1);
    TEST_ASSERT_EQUAL_POINT(3,3,"Wangsa Maju",end+2);
    TEST_ASSERT_EQUAL_POINT(1,3,"PV12",end+3);

    free(end);
}

/** (PV12)      (PV15)      (TARUC)       (Block D)     (Genting Klang)   (Wangsa Maju)   (Kajang)    (Cheras)        } 8 Random Coordinates
  *    .(-2,-1)   .(2,1)       .(8,3)         .(4,2)            .(8,5)          .(4,-1)       .(8,-3)      .(-1,-4)    } Search for the left most point
  *
  *  Found left most point (Pv12) and undergo Convex Hull through Jarvis March Algorithm in anticlockwise direction
  *            (PV12)           (Cheras)              (Pv12)           (Cheras)    (Kajang)                 ____
  *               .---------------.       -->             .----------------.-----------.                       |
  *                                                                                                            |
  *                               ___             (Pv12)        (Cheras)        (Kajang)         (TARUC)     <_|
  *                              |                   .--------------.---------------.---------------.
  *                              |
  *                              |_>              (Pv12)        (Cheras)        (Kajang)         (TARUC)    (Genting Klang)
  *                                                  .--------------.---------------.---------------.---------------.
  *
  *                           Other coordinates are enclosed inside the shape formed from the Convex Hull Algorithm
  *
  *
  *
**/

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
    Point *end = (convexHull(start , n , anticlockwise));
    TEST_ASSERT_EQUAL(8,n);
    TEST_ASSERT_EQUAL_POINT(-2,1,"PV12",end);
    TEST_ASSERT_EQUAL_POINT(-1,-4,"Cheras",end+1);
    TEST_ASSERT_EQUAL_POINT(8,-3,"Kajang",end+2);
    TEST_ASSERT_EQUAL_POINT(8,3,"TARUC",end+3);
    TEST_ASSERT_EQUAL_POINT(8,5,"Genting Klang",end+4);

    free(end);
}

/** (PV12)      (PV15)      (TARUC)       (Block D)     (Genting Klang)   (Wangsa Maju)       (Kajang)        (Cheras)          (Taman Melawati)      (Gombak)       } 10 Random Coordinates
  *    .(90,141)  .(95,243)    .(158,153)     .(50,197)        .(90,192)        .(161,214)       .(133,202)      .(124,183)           .(112,170)         .(105,210)  } Search for the left most point
  *
  *  Found left most point (Block D) and undergo Convex Hull through Jarvis March Algorithm in clockwise direction
  *            (Block D)       (Pv15)                  (Block D)        (Pv15)    (Wangsa Maju)             ____
  *               .---------------.       -->             .----------------.-----------.                       |
  *                                                                                                            |
  *                               ___             (Block D)      (Pv15)       (Wangsa Maju)      (TARUC)     <_|
  *                              |                   .--------------.---------------.---------------.
  *                              |
  *                              |_>              (Block D)      (Pv15)       (Wangsa Maju)      (TARUC)          (Pv12)
  *                                                  .--------------.---------------.---------------.---------------.
  *
  *                           Other coordinates are enclosed inside the shape formed from the Convex Hull Algorithm
  *
  *
  *
**/

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


    Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa\
                  ,pointKajang,pointCheras,pointTamanMelawati,pointGombak};

    int n = (sizeof(start))/(sizeof(start[0]));
    Point *end = (convexHull(start , n , clockwise));
    TEST_ASSERT_EQUAL(10,n);
    TEST_ASSERT_EQUAL_POINT(50,197,"Block D",end);
    TEST_ASSERT_EQUAL_POINT(95,243,"PV15",end+1);
    TEST_ASSERT_EQUAL_POINT(161,214,"Wangsa Maju",end+2);
    TEST_ASSERT_EQUAL_POINT(158,153,"TARUC",end+3);
    TEST_ASSERT_EQUAL_POINT(90,141,"PV12",end+4);

    free(end);
}

/** (PV12)      (PV15)      (TARUC)       (Block D)     (Genting Klang)   (Wangsa Maju)       (Kajang)        (Cheras)          (Taman Melawati)      (Gombak)      (Ampang Park)     (Masjid Jamek)      (KLCC)              } 13 Random Coordinates
  *    .(90,141)  .(80,180)    .(158,153)     .(56,253)        .(156,255)        .(28,196)       .(197,199)      .(119,275)           .(116,111)         .(110,117)        .(181,274)        .(20,117)       .(177,141)       }Search for the left most point
  *
  *  Found left most point (Masjid Jamek) and undergo Convex Hull through Jarvis March Algorithm in clockwise direction
  *            (Masjid Jamek)       (Wangsa Maju)   (Masjid Jamek)   (Wangsa Maju)  (Block D)               ____
  *               .---------------.       -->             .----------------.-----------.                       |
  *                                                                                                            |
  *                               ___         (Masjid Jamek)  (Wangsa Maju)    (Block D)      (Cheras)       <_|
  *                              |                   .--------------.---------------.---------------.
  *                              |
  *                              |_>          (Masjid Jamek)  (Wangsa Maju)     (Block D)        (Cheras)     (Ampang Park)                     ____
  *                                                  .--------------.---------------.---------------.---------------.                              |
  *                                                                                                                                                |
  *                              ___          (Masjid Jamek)  (Wangsa Maju)     (Block D)        (Cheras)     (Ampang Park)         (Kajang)     <_|
  *                             |                    .--------------.---------------.---------------.---------------.------------------.
  *                             |
  *                             |_>          (Masjid Jamek)  (Wangsa Maju)     (Block D)        (Cheras)     (Ampang Park)          (Kajang)    (KLCC)                            ____
  *                                                  .--------------.---------------.---------------.---------------.------------------.-----------.                                 |
  *                                                                                                                                                                                  |
  *                                          (Masjid Jamek)  (Wangsa Maju)     (Block D)        (Cheras)     (Ampang Park)         (Kajang)     (KLCC)      (Taman Melawati)       <_|
  *                                                 .--------------.---------------.---------------.---------------.------------------.------------.----------------.
  *                           Other coordinates are enclosed inside the shape formed from the Convex Hull Algorithm
  *
  *
  *
**/

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


    Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa\
                  ,pointKajang,pointCheras,pointTamanMelawati,pointGombak\
                  ,pointAmpangPark,pointMasjidJamek,pointKLCC};

    int n = (sizeof(start))/(sizeof(start[0]));
    Point *end = (convexHull(start , n , clockwise));
    TEST_ASSERT_EQUAL(13,n);
    TEST_ASSERT_EQUAL_POINT(20,117,"Masjid Jamek",end);
    TEST_ASSERT_EQUAL_POINT(28,196,"Wangsa Maju",end+1);
    TEST_ASSERT_EQUAL_POINT(56,253,"Block D",end+2);
    TEST_ASSERT_EQUAL_POINT(119,275,"Cheras",end+3);
    TEST_ASSERT_EQUAL_POINT(181,274,"Ampang Park",end+4);
    TEST_ASSERT_EQUAL_POINT(197,199,"Kajang",end+5);
    TEST_ASSERT_EQUAL_POINT(177,141,"KLCC",end+6);
    TEST_ASSERT_EQUAL_POINT(116,111,"Taman Melawati",end+7);

    free(end);
}
/*                                                                       .
 *        .       -->       \______. ---->           ./ ---->            | --------------
 *               anticlowise                  \_____./                 ./               |
 *                                                             \_____./                 |
 *                                                                                      |
 *                                                                                      |
 *                                                                                      |
 *                                                                                      |
 *         .____.          .____.          .____.          .____.                 .     |
 *       ./     \.       ./      \.      ./      \.              \.                \.   |
 *     ./       | <--- ./        | <---          | <---          |     <--         |  <_|
 *   .|       ./               ./              ./              ./                ./
 *    \_____./         \_____./        \_____./        \_____./          \_____./
 *
*/
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


    Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa\
                  ,pointKajang,pointCheras,pointTamanMelawati,pointGombak\
                  ,pointAmpangPark,pointMasjidJamek,pointKLCC};

    int n = (sizeof(start))/(sizeof(start[0]));
    Point *end = (convexHull(start , n , anticlockwise));
    TEST_ASSERT_EQUAL(13,n);
    TEST_ASSERT_EQUAL_POINT(20,117,"Masjid Jamek",end);
    TEST_ASSERT_EQUAL_POINT(116,111,"Taman Melawati",end+1);
    TEST_ASSERT_EQUAL_POINT(177,141,"KLCC",end+2);
    TEST_ASSERT_EQUAL_POINT(197,199,"Kajang",end+3);
    TEST_ASSERT_EQUAL_POINT(181,274,"Ampang Park",end+4);
    TEST_ASSERT_EQUAL_POINT(119,275,"Cheras",end+5);
    TEST_ASSERT_EQUAL_POINT(56,253,"Block D",end+6);
    TEST_ASSERT_EQUAL_POINT(28,196,"Wangsa Maju",end+7);

    free(end);
}

/** (PV12)      (PV15)      (TARUC)       (Block D)     (Genting Klang)   (Wangsa Maju)       (Kajang)        (Cheras)          (Taman Melawati)      (Gombak)      (Ampang Park)     (Masjid Jamek)      (KLCC)            (Sri Rampai)        (Setiawangsa)     (Jelatek)       (Dato Keramat)    (Damai)         (Kampung Baru) \        }
  *     .(90,141)  .(96,206)    .(90,153)     .(56,253)        .(105,166)        .(31,196)       .(197,199)      .(119,275)           .(116,111)         .(114,172)        .(181,274)        .(20,117)       .(177,141)         .(62,240)             .(105,248)       .(144,233)       .(130,206)     .(163,173)           .(148,155)      }
  * (Pasar Seni)    (KL Sentral)      (Bangsar)     (Abdullah Hukum)      (Kerinchi)        (Universiti)       (Taman Jaya)       (Asia Jaya)            \                                                                                                                                                                                  }
  *       .(121,131)      .(107,118)      .(95,117)         .(72,122)          .(31,119)          .(38,191)          .(75,163)          .(60,144)                                                                                                                                                                                           }  30 Random Coordinates *                                                                                                                                                                                                                                                                                                                                         }                                                                                                                                                                   * * * (Taman Paramount)    (Taman Bahagia)       (Kelana Jaya)                                                                                                                                                                                                                                                                                }  Search for the left most point
  *        .(76,128)           .(116,140)             .(144,172)                                                                                                                                                                                                                                                                            }
  *
  *
  *  Found left most point (Masjid Jamek) and undergo Convex Hull through Jarvis March Algorithm in anticlockwise direction
  *            (Masjid Jamek) (Taman Melawati)     (Masjid Jamek)   (Taman Melawati)  (KLCC)               ____
  *               .---------------.       -->             .----------------.------------.                     |
  *                                                                                                           |
  *                               ___         (Masjid Jamek)  (Taman Melawati)   (KLCC)         (Kajang)    <_|
  *                              |                   .--------------.---------------.---------------.
  *                              |
  *                              |_>          (Masjid Jamek)  (Taman Melawati)   (KLCC)         (Kajang)     (Ampang Park)                      ____
  *                                                  .--------------.---------------.---------------.---------------.                              |
  *                                                                                                                                                |
  *                              ___          (Masjid Jamek)  (Taman Melawati)   (KLCC)         (Kajang)     (Ampang Park)         (Cheras)     <_|
  *                             |                    .--------------.---------------.---------------.---------------.------------------.
  *                             |
  *                             |_>          (Masjid Jamek)  (Taman Melawati)    (KLCC)         (Kajang)     (Ampang Park)          (Cheras)    (Block D)                         ____
  *                                                  .--------------.---------------.---------------.---------------.------------------.-----------.                                 |
  *                                                                                                                                                                                  |
  *                                          (Masjid Jamek)  (Taman Melawati)     (KLCC)        (Kajang)     (Ampang Park)         (Cheras)     (Block D)      (Wangsa Maju)       <_|
  *                                                 .--------------.---------------.---------------.---------------.------------------.------------.----------------.
  *                           Other coordinates are enclosed inside the shape formed from the Convex Hull Algorithm
  *
  *
  *
**/

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


    Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa\
                  ,pointKajang,pointCheras,pointTamanMelawati,pointGombak\
                  ,pointAmpangPark,pointMasjidJamek,pointKLCC,pointMasjidJamek\
                  ,pointSriRampai,pointSetiawangsa,pointJelatek,pointDK,pointDamai\
                  ,pointKB,pointPS,pointKLS,pointBangsar,pointAH,pointKerinchi\
                  ,pointUniversiti,pointTJ,pointAJ,pointTP,pointTB};

    int n = (sizeof(start))/(sizeof(start[0]));
    Point *end = (convexHull(start , n , anticlockwise));
    TEST_ASSERT_EQUAL(30,n);
    TEST_ASSERT_EQUAL_POINT(20,117,"Masjid Jamek",end);
    TEST_ASSERT_EQUAL_POINT(116,111,"Taman Melawati",end+1);
    TEST_ASSERT_EQUAL_POINT(177,141,"KLCC",end+2);
    TEST_ASSERT_EQUAL_POINT(197,199,"Kajang",end+3);
    TEST_ASSERT_EQUAL_POINT(181,274,"Ampang Park",end+4);
    TEST_ASSERT_EQUAL_POINT(119,275,"Cheras",end+5);
    TEST_ASSERT_EQUAL_POINT(56,253,"Block D",end+6);
    TEST_ASSERT_EQUAL_POINT(31,196,"Wangsa Maju",end+7);

    free(end);
}

/** (PV12)      (PV15)      (TARUC)       (Block D)     (Genting Klang)   (Wangsa Maju)  } 6 Random Coordinates
  *    .(0,3)     .(2,2)       .(1,1)         .(3,0)            .(0,0)          .(110,110)   } Search for the left most point
  *
  *  Found left most point(Genting Klang) and undergo Convex Hull through Jarvis March Algorithm in clockwise direction
  *        (Genting Klang)     (PV12)              (Genting Klang)       (PV12)                        (Wangsa Maju)                               ____
  *               .---------------.       -->             .----------------.--------------------------------.                                         |
  *                                                                                                                                                   |
  *                                         (Genting Klang)     (PV12)                                  (Wangsa Maju)     (Block D)                 <_|
  *                                                 .--------------.----------------------------------------.---------------.
  *
  *
  *                                Other coordinates are enclosed inside the shape formed from the Convex Hull Algorithm
  *
  *
  *
  *
  *
**/
void test_6_random_coordinates_with_one_out_of_range_point_after_Jarvis_algorithm_expect_starting_GK_clockwise_ending_BlockD(void)
{
    initN(&pointPv12,0,3);
    initN(&pointPv15,2,2);
    initN(&pointTaruc,1,1);
    initN(&pointBlockD,3,0);
    initN(&pointGK,0,0);
    initN(&pointWangsa,110,110);
    Point start[]={pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa};

    int n = (sizeof(start))/(sizeof(start[0]));
    Point *end = (convexHull(start , n , clockwise));

    TEST_ASSERT_EQUAL(6,n);
    TEST_ASSERT_EQUAL_POINT(0,0,"Genting Klang",end);
    TEST_ASSERT_EQUAL_POINT(0,3,"PV12",end+1);
    TEST_ASSERT_EQUAL_POINT(110,110,"Wangsa Maju",end+2);
    TEST_ASSERT_EQUAL_POINT(3,0,"Block D",end+3);

    free(end);
}
