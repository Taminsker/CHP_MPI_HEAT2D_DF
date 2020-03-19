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
        coeffs [4] = coef_c;

    return  coeffs;
}

std::vector <double> operator* (Matrix A, std::vector <double> x)
{
  // Test pour savoir si A et x ont des tailles compatibles

  int N = x.size ();
  std::vector <double> b (N);

  for (int i = 0; i < Nx; i++) {
    for (int j = 0; j < Ny; j++) {

      int index = j * Nx + i;

      b [index] *= GetMatrixLine (i,j) [2];

      if (index > 1)
        b [index] += GetMatrixLine (i,j) [1] * b[index - 1];

      if (index > Nx)
        b [index] += GetMatrixLine (i,j) [0] * b[index - Nx];

      if (index + 1 < N)
        b [index] += GetMatrixLine (i,j) [3] * b[index + 1];

      if (index + Nx < N)
        b [index] += GetMatrixLine (i,j) [4] * b[index + Nx];

    }
  }

  return b;

}
