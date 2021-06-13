#include "gps.h"
#include "string.h"
#define pi 3.1415926535897932384626433832795

float ToDegrees (float x)
{
	
		float deg = 0 ;
		float	min = 0;
		deg = (int)(x)/100;
		min = x - (deg*100);
		deg = deg + (min/60) ;
	return deg;
}

float ToRadian (float x)
{
	return ((x*(pi))/180) ;
}

float Calc_Distance (float longitude1,float longitude2,float latitude1,float latitude2)
{
	double dLat = (latitude2 - latitude1);
	double dLon = (longitude2 - longitude1);
	double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(latitude1) * cos(latitude2);
	double c = 2 * asin(sqrt(a));
	return (c*6371000) ;
}