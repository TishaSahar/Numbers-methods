﻿#include "source.h"

 
double sinA(double x, int nAp) {
    //if (x - 1.0 > 0.000000000001)
    //    return cos(1.570796327 - x);
    double tmp = 0.0;
    double pow = x;
    double fac = 1.0;
    for (int j = 1; j < nAp; j++) {
        tmp += pow / fac;
        pow = pow * x * x * (-1);
        fac = fac* (2 * j) * (2 * j + 1);
    }
    return tmp;
}



double cosA(double x, int nAp) {
    //if (x - 1.0 > 0.000000000001)
    //    return sin(1.570796327 - x);
    double tmp = 0.0;
    double pow = 1;
    double fac = 1;
    for (int j = 0; j < nAp; j++) {
        tmp += pow / fac;
        pow = pow * x * x * (-1);
        fac = fac * (2 * j + 1) * (2 * j + 2);
    }
    return tmp;
}


double shA(double value, int nAp) {
    double tmp = 0.0;
    double k = 1;
    double pow = value;
    for (int j = 1; j < nAp; j++) {
        tmp += pow / k;
        k = k * (2 * j) * (2 * j + 1);
        pow = pow * value * value;
    }
    return tmp;
}

double chA(double value, int nAp)
{
    double tmp = 0.0;
    double k = 1;
    double pow = 1.0;
    for (int j = 1; j < nAp; j++) {
        tmp += pow / k;
        k = k * (2 * j) * (2 * j + 2);
        pow = pow * value * value;
    }
    return tmp;
}


double lnA(double value, int nAp) {
    if (value < 1.0) {
        throw "received value < 1";
    }

    double x = (value - 1) / (value + 1);
    double tmp = 0.0;
    int i = 1;
    double mon = x;
    for (int j = 0; j < nAp + 5; j++) {
        tmp += mon / i;
        i += 2;
        mon = mon * x * x;
    }
    tmp *= 2.0;
    return tmp;
}






double supa(double X) {  // Верхняя граница для "а" и/или "b"
    return X + 0.00005;
}
double infa(double X) {	  // Нижняя граница для "a" и/или "b"
    return X - 0.0005;
}

double supA(double a, double b) { // Верхняя граница функции А
    return (exp(supa(a)) + sqrt(supa(b)))/log(infa(a) + infa(b)*infa(b));
}
double infA(double a, double b) { // Нижняя граница функции А
    return (exp(infa(a)) + sqrt(infa(b))) / log(supa(a) + supa(b) * supa(b));
}

double deltaA(double a, double b) {
    return (supA(a, b) - infA(a, b)) / 2;
}

double A(double a, double b) {
    return (supA(a, b) + infA(a, b)) / 2;
}

                                            // Интерполяция

double monom(double x, int j, int n, double* arg) {
    double m = 1.0;

    for (int k = 0; k <= n; k++) {
        if (j == k) continue;
        m *= (x - arg[k]);
        m /= (arg[j] - arg[k]);
    }
    
    return m;
}

double Lagrange(double x, int n, double* arg, double* func) {
    double L = 0.0;

    for (int j = 0; j < n; j++) {
        L += func[j] * monom(x, j, n, arg);
    }

    return L;
}


double supX(double X, double h) {  //
    return exp(X + h);
}
double infX(double X, double h) {	  // 
    return exp(X - h);
}
double _derivative(double x, double h)
{
    double k = 2.0;
    return (supX(x, h) - infX(x, h)) / (k * h); //
}

double derivative(double x)
{
    return exp(x);                         //  exp(x)
}

double deltaX(double x, double h)
{
    return fabs(derivative(x) - _derivative(x, h)); // = 
}

double M3(double x, double h)
{
    return fabs(supX(x, h));  // 
}

double searchH(double x, double h)
{
    double E = (0.5) * pow(10, -4);
    //std::cout << E << std::endl;
    //std::cout << M3(x,h) << std::endl;
    //std::cout << (3.0 * E) / M3(x, h) << std::endl;
    //std::cout << _derivative(x, h) << std::endl;
    return pow((3.0 * E) / M3(x, h), (1.0 / 3.0));                                       // 
}

                                                        // 5-я лаба

double RK2(double x0, double y0, int n) {
    double xtemp = x0, ytemp = y0, ftemp;
    double h = 1 / n;

    for (int i = 0; i < n; i++) {
        ftemp = ytemp - xtemp;
        ytemp = ytemp + h * 0.5 * (ftemp + ytemp + h * ftemp - xtemp - h);

        xtemp += h;

    }

    std::cout << "Метод Рунге-Кутта 2 порядка: " << ytemp << std::endl;
    return ytemp;
}


double RK3(double x0, double y0, int n) {
    double xtemp = x0, ytemp = y0, ftemp;
    double h = 1 / n;
    double k1, k2, k3;

    for (int i = 0; i < n; i++) {
        k1 = h * (ytemp - xtemp);
        k2 = h * (ytemp + k1 / 2 - xtemp - h / 2);
        k3 = h * (ytemp - k1 + 2 * k2 - xtemp - h);

        ytemp = ytemp + (k1 + 4 * k2 + k3) / 6;

        xtemp += h;

    }

    std::cout << "Метод Рунге-Кутты 3 порядка: " << ytemp << std::endl;
    return ytemp;
}


double RK4(double x0, double y0, int n) {
    double xtemp = x0, ytemp = y0, ytemp1 = y0, ftemp;
    double h = 1 / n, h1;
    double k1, k2, k3, k4, k11, k21, k31, k41;
    double e;

    for (int i = 0; i < n; i++) {
        k1 = ytemp - xtemp;
        k2 = ytemp + h * k1 / 2 - xtemp - h / 2;
        k3 = ytemp + h * k2 / 2 - xtemp - h / 2;
        k4 = ytemp + h * k3 - xtemp - h;

        ytemp = ytemp + h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        /*h1 = h / 2;

        k1 = ytemp1 - xtemp;
        k2 = ytemp1 + h1 * k1 / 2 - xtemp - h1 / 2;
        k3 = ytemp1 + h1 * k2 / 2 - xtemp - h1 / 2;
        k4 = ytemp1 + h1 * k3 - xtemp - h1;

        ytemp1 = ytemp1 + h1 * (k1 + 2 * k2 + 2 * k3 + k4) / 6;

        e = (2 ^ 4) * (ytemp1 - ytemp) / (2 ^ 4 - 1);

        */

        xtemp += h;


    }

    std::cout << "Метод Рунге-Кутты 4 порядка: " << ytemp << std::endl;
    return ytemp;
}




