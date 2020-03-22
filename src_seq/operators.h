#ifndef OPERATORS_H
#define OPERATORS_H

#include <vector>
#include <stdio.h>
#include <string>

typedef std::vector <double> Vector;

double operator| (Vector x, Vector y);

Vector operator+ (Vector x, Vector y);

Vector operator- (Vector x, Vector y);

Vector operator+= (Vector &x, Vector y);

Vector operator-= (Vector &x, Vector y);

Vector operator* (double k, Vector x);

Vector operator* (Vector x, double k);

Vector operator*= (Vector &x, double k);

void print (std::string name, Vector a, size_t dispSize = 5);

#endif // OPERATORS_H
