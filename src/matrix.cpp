#include "matrix.h"


Matrix::Matrix (int Nx, int Ny, double Lx, double Ly, double D, double dt) :
    m_Nx (Nx), m_Ny (Ny)
{
    double dx = Lx / double (Nx);
    double dy = Ly / double (Ny);

    coef_b = coef_c = - D * dt;
    coef_b /= dx * dx;
    coef_c /= dy * dy;
    coef_a = 1. - 2. * coef_b - 2. * coef_c;
}

Matrix::~Matrix ()
{}

std::vector <double> Matrix::GetMatrixLine (int i, int j)
{
    std::vector <double> coeffs (5, 0.);

    coeffs [2] = coef_a;

    if (i > 0) // contribution du pt i-1
        coeffs [1] = coef_b;
    if (i < m_Nx) // contribution du pt i+1
        coeffs [3] = coef_b;

    if (j > 0) // contribution du pt j-1
        coeffs [0] = coef_c;
    if (j < m_Ny) // contribution du pt j+1
        coeffs [4] = coef_b;

    return  coeffs;
}
