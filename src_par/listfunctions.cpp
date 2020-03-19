#include <cmath>

#include "listfunctions.h"

// CAS TEST 1

double f_1 (double x, double y, double t)
{
  return 2. * (y - y * y + x - x * x);
}

double g_1 (double x, double y, double t)
{
  return 0.;
}

double h_1 (double x, double y, double t)
{
  return 0.;
}


// CAS TEST 2

double f_2 (double x, double y, double t)
{
  return sin(x) + cos(y);
}

double g_2 (double x, double y, double t)
{
  return sin(x) + cos(y);
}

double h_2 (double x, double y, double t)
{
  return sin(x) + cos(y);
}


// CAS TEST 3

double f_3 (double x, double y, double t)
{
  //return exp (- (x - (Lx / 2.)) * (x - (Lx / 2.))) * exp (- (y - (Ly / 2.)) * (y - (Ly / 2.))) * cos((PI / 2.) * t);
  return 0.;
}

double g_3 (double x, double y, double t)
{
  return 0.;
}

double h_3 (double x, double y, double t)
{
  return 1.;
}
