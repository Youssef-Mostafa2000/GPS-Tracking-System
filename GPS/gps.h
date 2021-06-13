#ifndef GPS_H_
#define GPS_H_
#include "stdint.h"
#include "math.h"

float ToDegrees (float x);
float ToRadian (float x);
float Calc_Distance (float longitude1,float longitude2,float latitude1,float latitude2);

#endif
