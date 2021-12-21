#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
												// 1-е задание
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



double lnA(double x, double numAftPnt);

												// 2-е задание

double supa(double X);	  // Верхняя граница для "а" и/или "b"
double infa(double X);	  // Нижняя граница для "a" и/или "b"

double supA(double a, double b); // Верхняя граница функции А
double infA(double a, double b); // Нижняя граница функции А


double deltaA(double a, double b); // Погрешнисть вычисления функции А
double A(double a = 2.156, double b = 0.9270); // Вычисление функции А по методу границ


												// 3-е задание

double monom(double x = 0.0, int j = 0, int n = 5, double* arg = NULL);
double Lagrange(double x = 0.0, int n = 5, double* arg = {}, double* func = {});
                  
                                                // 4-е задание 

double _derivative(double x, double h); // Приближенное значение производной

double supX(double X, double h);  // Верхняя граница для x+h
	
double infX(double X, double h);  // Нижняя граница для x-h

double derivative(double x);   // Производная exp(x)

double deltaX(double x, double h); // Абсолюнтая прогрешность

double M3(double x, double h); // Константа М3

double searchH(double x, double h);  // Нахождение оптимального шага