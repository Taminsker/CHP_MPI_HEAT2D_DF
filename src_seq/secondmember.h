#ifndef SECOND_MEMBER_H
#define SECOND_MEMBER_H

#include <vector>
#include "listfunctions.h"

std::vector <double> Set_vector_b0 (double (*g) (double, double, double),
                                    const Matrix &A);

std::vector <double> Set_vector_b1 (double (*h) (double, double, double),
                                    const Matrix &A);

std::vector <double> Set_vector_f (double (*f) (double, double, double),
                                  double t, const Matrix &A);

#endif// SECOND_MEMBER_H
