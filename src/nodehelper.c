#include "nodehelper.h"


extern Point pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa\
            ,pointKajang,pointCheras,pointTamanMelawati,pointGombak,pointDangWangi\
            ,pointAmpangPark,pointKLCC,pointMasjidJamek\
            ,pointSriRampai
            ,pointSetiawangsa
            ,pointJelatek
            ,pointDK
            ,pointDamai
            ,pointKB
            ,pointPS
            ,pointKLS
            ,pointBangsar
            ,pointAH
            ,pointKerinchi
            ,pointUniversiti
            ,pointTJ
            ,pointAJ
            ,pointTP
            ,pointTB
            ,pointKJ;

;

void initN(Point *points,int x,int y)
{
  points->x = x;
  points->y = y;
}


void initNnode(void){
  pointPv12.place = "PV12";
  pointPv15.place = "PV15";
  pointTaruc.place = "TARUC";
  pointBlockD.place = "Block D";
  pointGK.place = "Genting Klang";
  pointWangsa.place = "Wangsa Maju";
  pointKajang.place = "Kajang";
  pointCheras.place = "Cheras";
  pointTamanMelawati.place = "Taman Melawati";
  pointGombak.place = "Gombak";
  pointDangWangi.place = "Dang Wangi";
  pointAmpangPark.place = "Ampang Park";
  pointKLCC.place = "KLCC";
  pointMasjidJamek.place = "Masjid Jamek";
  pointSriRampai.place = "Sri Rampai";
  pointSetiawangsa.place = "Setiawangsa";
  pointJelatek.place = "Jelatek";
  pointDK.place = "Dato Keramat";
  pointDamai.place = "Damai";
  pointKB.place = "Kampung Baru";
  pointPS.place = "Pasar Seni";
  pointKLS.place = "KL Sentral";
  pointBangsar.place = "Bangsar";
  pointAH.place = "Abdulllah Hukum";
  pointKerinchi.place = "Kerinchi";
  pointUniversiti.place = "Universiti";
  pointTJ.place = "Taman Jaya";
  pointAJ.place = "Asia Jaya";
  pointTP.place = "Taman Paramount";
  pointTB.place = "Taman Bahagia";
  pointKJ.place = "Kelana Jaya";

}
