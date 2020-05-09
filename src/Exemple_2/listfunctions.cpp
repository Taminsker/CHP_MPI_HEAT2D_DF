#include "listfunctions.h"

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

// SOLUTION ANALYTIQUE CAS 2

double u_ana2 (double x, double y, double t)
{
    (void)t;
    return sin(x) + cos(y);
}

