#ifndef SOLVER_HEAT_2D
#define SOLVER_HEAT_2D

#include <cmath>
#include "operators.h"
#include "matrix.h"

Vector conj_gradient (const Matrix &A, const Vector &x);

double GetErrorl2 (double (*u_ana) (double, double, double), Vector x, const Matrix &A);

#endif// SOLVER_HEAT_2D
