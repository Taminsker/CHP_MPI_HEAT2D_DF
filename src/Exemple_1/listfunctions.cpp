#include "listfunctions.h"


// CAS TEST 1

double f_1 (const Problem &A, double x, double y, double t)
{
    (void)A;
    (void)t;
    return 2. * (y - y * y + x - x * x);
}

double g_1 (double x, double y, double t)
{
    (void)x;
    (void)y;
    (void)t;
    return 0.;
}

double h_1 (double x, double y, double t)
{
    (void)x;
    (void)y;
    (void)t;
    return 0.;
}

// SOLUTION ANALYTIQUE CAS 1

double u_ana1 (double x, double y, double t)
{
    (void)t;
    return ( (y - y * y) * (x - x * x) );
}
