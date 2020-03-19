#ifndef LISTFUNCTIONS_H
#define LISTFUNCTIONS_H

#include <cmath>

#include "matrix.h"

#define PI 3.14159265

double f_1 (double x, double y, double t = 0.);
double g_1 (double x, double y, double t = 0.);
double h_1 (double x, double y, double t = 0.);

double f_2 (double x, double y, double t = 0.);
double g_2 (double x, double y, double t = 0.);
double h_2 (double x, double y, double t = 0.);

double f_3 (double x, double y, double t, const Matrix &A);
double g_3 (double x, double y, double t = 0.);
double h_3 (double x, double y, double t = 0.);

#endif // LISTFUNCTIONS_H
