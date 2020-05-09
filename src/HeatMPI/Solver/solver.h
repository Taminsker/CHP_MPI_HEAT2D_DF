#ifndef SOLVER_H
#define SOLVER_H

#include <cmath>

#include "../Tools/tools.h"
#include "../Problem/problem.h"
#include "../ProcStruct/procstruct.h"

Vector ConjuguateGradient (const Problem& A, const Vector& x);

double GetErrorl2 (double (*u_ana) (double, double, double), const Vector& x, const Problem& A);

#endif // SOLVER_H
