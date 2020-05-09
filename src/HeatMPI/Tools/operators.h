#ifndef OPERATORS_H
#define OPERATORS_H

#include <mpi.h>
#include "datatype.h"

double operator| (const Vector &x, const Vector &y);

Vector operator+ (const Vector &x, const Vector &y);

Vector operator- (const Vector &x, const Vector &y);

Vector& operator+= (Vector &x, const Vector &y);

Vector& operator-= (Vector &x, const Vector &y);

Vector operator* (double k, const Vector &x);

Vector operator* (const Vector &x, double k);

Vector& operator*= (Vector &x, double k);


#endif // OPERATORS_H
