#ifndef SOLVER_HEAT_2D
#define SOLVER_HEAT_2D

#include <vector>
#include <stdio.h>

double operator| (const std::vector<double> &x, const std::vector<double> &y);

std::vector<double> operator+ (const std::vector<double> &x, const std::vector<double> &y);

std::vector<double> operator- (const std::vector<double> &x, const std::vector<double> &y);

void operator+= (std::vector<double> &x, const std::vector<double> &y);

void operator-= (std::vector<double> &x, const std::vector<double> &y);

std::vector<double> operator* (double k, std::vector<double> x);

std::vector<double> operator* (std::vector<double> x, double k);

void print (std::vector<double> a);

#endif// SOLVER_HEAT_2D
