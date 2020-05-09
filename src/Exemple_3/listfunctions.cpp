#include "listfunctions.h"


// CAS TEST 3

double f_3 (const Problem &A, double x, double y, double t)
{
    return exp (- (x - (A.Lx / 2.)) * (x - (A.Lx / 2.))) * exp (- (y - (A.Ly / 2.)) * (y - (A.Ly / 2.))) * cos((PI / 2.) * t);
}

double g_3 (double x, double y, double t)
{
    (void)x;
    (void)y;
    (void)t;
    return 0.;
}

double h_3 (double x, double y, double t)
{
    (void)x;
    (void)y;
    (void)t;
    return 1.;
}
