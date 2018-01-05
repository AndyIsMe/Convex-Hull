#include "nodehelper.h"


extern Point pointPv12,pointPv15,pointTaruc,pointBlockD,pointGK,pointWangsa;

void initN(Point *points,double x,double y)
{
  points->x = x;
  points->y = y;
}


void initNnode(void){
  pointPv12.place = "PV12";
  pointPv15.place = "PV15";
  pointTaruc.place = "TARUC";
  pointBlockD.place = "BlockD";
  pointGK.place = "GentingKlang";
  pointWangsa.place = "WangsaMaju";
}
