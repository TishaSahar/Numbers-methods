#pragma once

#include <iostream>
#include <cmath>

struct angle {
	double grad = 0;
	double min = 0;
	double sec = 0;

	double rad;

	void toRad() { rad = (grad / 57.2958) + (min / (60.0 * 57.2958)) + (sec / (3600.0 * 57.2958)); }
	void toGrad() { grad = round(rad * 0.017453);  min = 0.000291 * rad; sec = 0.000005 * rad; }
};


double fac(int n);


double sinA(angle a, int numAftPnt);
double cosA(angle a, double numAftPnt);


double shA(double value, double numAftPnt);
double chA(double value, double numAftPnt);
=======
double shA  (double a, double numAftPnt); 
double chA  (double a, double numAftPnt);


double lnA(double x, double numAftPnt);
