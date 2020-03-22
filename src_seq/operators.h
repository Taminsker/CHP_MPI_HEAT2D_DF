#ifndef OPERATORS_H
#define OPERATORS_H

#include <vector>
#include <stdio.h>
#include <string>

typedef std::vector <double> Vector;

double operator| (const Vector &x, const Vector &y);

Vector operator+ (const Vector &x, const Vector &y);

Vector operator- (const Vector &x, const Vector &y);

Vector& operator+= (Vector &x, const Vector &y);

Vector& operator-= (Vector &x, const Vector &y);

Vector operator* (double k, const Vector &x);

Vector operator* (const Vector &x, double k);

Vector& operator*= (Vector &x, double k);

void print (std::string name, Vector a, size_t dispSize = 5);

#endif // OPERATORS_H
