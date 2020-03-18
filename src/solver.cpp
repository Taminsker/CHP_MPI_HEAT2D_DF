#include "solver.h"

std::vector <double> conj_gradient (Matrix A, std::vector <double> b)
{
  // Test pour savoir si A et x ont des tailles compatibles

  int size = b.size ();

  double eps = 1e-5;

  std::vector <double> x (size, 0.);
  std::vector <double> r = b;
  std::vector <double> p = r;

  for (int k = 0; k < N; k++) {

    double alpha = (r | r) / (A * p | p);

    x += alpha * p;

    std::vector <double> r_bis = r - alpha * (A * p);

    if ( sqrt( (r_bis | r_bis) ) < eps)
      return x;

    double beta = (r_bis | r_bis) / (r | r);

    p *= beta;
    p += r_bis;
  }

  return x;
}
