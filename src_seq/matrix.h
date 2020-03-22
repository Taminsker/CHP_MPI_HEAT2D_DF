#ifndef MATRIX_HEAT_2D
#define MATRIX_HEAT_2D

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "operators.h"

class Matrix
{
public:
    Matrix ();
    ~Matrix ();

    void ReadParamFile (std::string filename = "param.dat");
    void SetStationnaire ();

    int Nx, Ny;
    double Lx, Ly;
    double dx, dy;
    double D, dt;
    double coeff_a, coeff_b, coeff_c;
};

Vector operator* (const Matrix &A, const Vector &x);
Vector operator* (const Vector &x, const Matrix &A);

/* Affichage de matrice : bloc [infr, infc] x [supr, supc] */
void print (std::string name, const Matrix &A, int infr = 0, int supr = 0, int infc = 0, int supc = 0);


#endif // MATRIX_HEAT_2D
