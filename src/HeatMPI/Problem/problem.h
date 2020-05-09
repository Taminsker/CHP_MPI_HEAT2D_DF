#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>


#include "../Tools/datatype.h"

struct Problem
{
    Problem (std::string filename = "params.dat");
    ~Problem ();
    void SetStationnary ();

    size_t Nx, Ny;
    double Lx, Ly;
    double dx, dy;
    double D, dt;
    double a, b, c;
};

Vector operator* (const Problem &A, const Vector &u);
Vector operator* (const Vector &u, const Problem &A);

#endif // PROBLEM_H
