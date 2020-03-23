#ifndef SECOND_MEMBER_H
#define SECOND_MEMBER_H

#include <vector>
#include "listfunctions.h"
#include "operators.h"

Vector Set_vector_b0 (double (*g) (double, double, double),
                                    const Matrix &A);

Vector Set_vector_b1 (double (*h) (double, double, double),
                                    const Matrix &A);

Vector Set_vector_f (double (*f) (Matrix, double, double, double),
                                  double t, const Matrix &A);

#endif// SECOND_MEMBER_H
