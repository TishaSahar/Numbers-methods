#include "source.h"


double fac(int n) {
    double f = 1.0; double tmp = f;
    for (int i = 0; i < n-1; i++) {
        tmp = tmp + 1.0;
        f = f * tmp;
    }
    //std::cout << f << std::endl;
    return f;
}

double sinA(angle a, int numAftPnt) {
    double sin = a.rad; double j = 1.0;
    for (int i = 1; i <= 5; i++) {
        sin = sin + pow(-1.0, i) * pow(a.rad, 2 * i + 1) / fac(2*i + 1);
    }
    
    return sin;
}
double cosA(angle a, double numAftPnt) {
    double cos = 1.0; double j = 1.0;
    for (int i = 1; i <= 5; i++) {
        cos = cos + pow(-1.0, i) * pow(a.rad, 2 * i) / fac(2 * i);
    }

    return cos;
}

double shA(double  a, double numAftPnt) { return a; }
double chA(double  a, double numAftPnt) { return a; }

double lnA(double x, double numAftPnt) {
    double ln = 0.0;

    if (x - 1.0 < 0.0000001) {
        std::cout << "ln(x) not definded" << std::endl;
        return -1;
    }

    for (int i = 1; i <= numAftPnt; i++) {
        ln = ln + pow(-1.0, i + 1) * pow(x, i) / i;
    }

}