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


// CAS TEST 2

double f_2 (const Problem &A, double x, double y, double t)
{
    (void)A;
    (void)t;
    return std::sin(x) + std::cos(y);
}

double g_2 (double x, double y, double t)
{
    (void)t;
    return std::sin(x) + std::cos(y);
}

double h_2 (double x, double y, double t)
{
    (void)t;
    return std::sin(x) + std::cos(y);
}

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


// SOLUTION ANALYTIQUE CAS 1

double u_ana1 (double x, double y, double t)
{
    (void)t;
    return ( (y - y * y) * (x - x * x) );
}


// SOLUTION ANALYTIQUE CAS 2

double u_ana2 (double x, double y, double t)
{
    (void)t;
    return sin(x) + cos(y);
}

