#ifndef SOLVER_HEAT_2D
#define SOLVER_HEAT_2D

#include <cmath>

#include "operators.h"
#include "matrix.h"

Vector conj_gradient (const Matrix &A, Vector &x);

#endif// SOLVER_HEAT_2D
