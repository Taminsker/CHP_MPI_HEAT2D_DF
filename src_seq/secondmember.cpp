#include "secondmember.h"

std::vector <double> Set_vector_b0 (double (*g) (double, double, double),
                                    const Matrix &A)
{
  std::vector <double> vec_b0 (A.Nx * A.Ny);

  for (int i = 0; i < A.Nx; i++)
  {
    vec_b0 (i) = g (i * A.dx, 0.); // Bord inférieur Gamma_0

    vec_b0 ((A.Ny - 1) * A.Nx + i) = g (i * A.dx, A.Lx); // Bord supérieur Gamma_0
  }

  vec_b0 *= - A.coef_c;
}


std::vector <double> Set_vector_b1 (double (*h) (double, double, double),
                                    const Matrix &A);
{
  std::vector <double> vec_b1 (A.Nx * A.Ny);

  for (int i = 0; i < (A.Nx * A.Ny); i++)
  {
    if (i % A.Nx == 0)
    {
      vec_b1 (i) = h (0., (i % A.Nx) * A.dy); // Bord gauche Gamma_1

      vec_b1 (i + A.Nx - 1) = h (A.Ly, (i % A.Nx) * A.dy); // Bord droit Gamma_1
    }
  }

  vec_b1 *= - A.coef_b;
}


std::vector <double> Set_vector_f (double (*f) (double, double, double),
                                  double t, const Matrix &A)
{
  std::vector <double> vec_f (A.Nx * A.Ny);

  for (int i = 0; i < A.Nx; i++) {
    for (int j = 0; j < A.Ny; j++) {

      vec_f (j * A.Nx + i) = f ( (i + 1) * A.dx, (j + 1) * A.dy, t);

    }
  }

}
