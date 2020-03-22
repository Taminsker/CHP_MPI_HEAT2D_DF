#include "secondmember.h"

std::vector <double> Set_vector_b0 (double (*g) (double, double, double),
                                    const Matrix &A)
{
  std::vector <double> vec_b0 (A.Nx * A.Ny, 0.);

  for (int i = 0; i < A.Nx; i++)
  {
    vec_b0 [i] = g ((i + 1) * A.dx, 0., 0.); // Bord inférieur Gamma_0

    vec_b0 [(A.Ny - 1) * A.Nx + i] = g ((i + 1) * A.dx, A.Ly, 0.); // Bord supérieur Gamma_0
  }

  vec_b0 *= - A.coeff_c;

  return vec_b0;
}


std::vector <double> Set_vector_b1 (double (*h) (double, double, double),
                                    const Matrix &A)
{
  std::vector <double> vec_b1 (A.Nx * A.Ny, 0.);

  for (int j = 0; j < A.Ny; j++)
  {
      vec_b1 [j * A.Nx] = h (0., (j + 1) * A.dy, 0.); // Bord gauche Gamma_1

      vec_b1 [(j + 1) * A.Nx - 1)] = h (A.Lx, (j + 1) * A.dy, 0.); // Bord droit Gamma_1
  }

  vec_b1 *= - A.coeff_b;

  return vec_b1;
}


std::vector <double> Set_vector_f (double (*f) (double, double, double),
                                  double t, const Matrix &A)
{
  std::vector <double> vec_f (A.Nx * A.Ny, 0.);

  for (int i = 0; i < A.Nx; i++) {
    for (int j = 0; j < A.Ny; j++) {

      vec_f [j * A.Nx + i] = f ( (i + 1) * A.dx, (j + 1) * A.dy, t);

    }
  }

  return vec_f;
}
