#ifndef LISTFUNCTIONS_H
#define LISTFUNCTIONS_H

#include <cmath>

#include "matrix.h"

#define PI 3.14159265

// CAS TEST 1
double f_1 (double x, double y, double t = 0.);
double g_1 (double x, double y, double t = 0.);
double h_1 (double x, double y, double t = 0.);

// CAS TEST 2
double f_2 (double x, double y, double t = 0.);
double g_2 (double x, double y, double t = 0.);
double h_2 (double x, double y, double t = 0.);

// CAS TEST 3
double f_3 (double x, double y, double t = 0., const Matrix &A);
double g_3 (double x, double y, double t = 0.);
double h_3 (double x, double y, double t = 0.);

// SOLUTIONS ANALYTIQUES CAS 1 ET 2
double u_ana1 (double x, double y, double t = 0.);
double u_ana2 (double x, double y, double t = 0.);

#endif // LISTFUNCTIONS_H
