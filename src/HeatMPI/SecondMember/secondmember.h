#ifndef SECONDMEMBER_H
#define SECONDMEMBER_H

#include "../Tools/tools.h"
#include "../ProcStruct/procstruct.h"
#include "../Problem/problem.h"

Vector VectorBoundaryUpTop (double (*f) (double, double, double), const Problem &A);

Vector VectorBoundaryLeftRight (double (*f) (double, double, double), const Problem &A);

Vector VectorSecondMember (double (*f) (const Problem&, double, double, double), double t, const Problem &A);

#endif // SECONDMEMBER_H
