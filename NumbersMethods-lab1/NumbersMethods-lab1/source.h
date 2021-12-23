#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
													// 1-я лаба
struct angle {
	double grad = 0;
	double min = 0;
	double sec = 0;

	double rad;

	void toRad() { rad = (grad / 57.2958) + (min / (60.0 * 57.2958)) + (sec / (3600.0 * 57.2958)); }
	void toGrad() { grad = round(rad * 0.017453);  min = 0.000291 * rad; sec = 0.000005 * rad; }
};


//double fac(int n);


double sinA(double x, int nAp);
double cosA(double x, int nAp);


double shA(double value, int nAp);
double chA(double value, int nAp);



double lnA(double value, int nAp);

												// 2-я лаба

double supa(double X);	  
double infa(double X);	  

double supA(double a, double b); 
double infA(double a, double b); 


double deltaA(double a, double b); 
double A(double a = 2.156, double b = 0.9270); // Считаем функцию методом границ


												// 3-я лаба

double monom(double x = 0.0, int j = 0, int n = 5, double* arg = NULL);
double Lagrange(double x = 0.0, int n = 5, double* arg = {}, double* func = {});

												// 4-я лаба

double _derivative(double x, double h); // Ďđčáëčćĺííîĺ çíŕ÷ĺíčĺ ďđîčçâîäíîé

double supX(double X, double h);  // Âĺđőí˙˙ ăđŕíčöŕ äë˙ x+h

double infX(double X, double h);  // Íčćí˙˙ ăđŕíčöŕ äë˙ x-h

double derivative(double x);   // Ďđîčçâîäíŕ˙ exp(x)

double deltaX(double x, double h); // Ŕáńîëţíňŕ˙ ďđîăđĺříîńňü

double M3(double x, double h); // Ęîíńňŕíňŕ Ě3

double searchH(double x, double h);  // Íŕőîćäĺíčĺ îďňčěŕëüíîăî řŕăŕ


													//