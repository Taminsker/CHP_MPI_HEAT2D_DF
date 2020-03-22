#include "solver.h"

Vector conj_gradient (const Matrix &A, const Vector &b)
{
    int N = b.size ();

    if (N != (A.Nx * A.Ny)) return Vector (N, 0.);

    double eps = 1e-5;

    Vector x (N, 0.);
    double alpha, beta, rNorm;
    Vector r = b - (A * x);
    Vector p = b - (A * x);
    Vector r_bis;

    for (int k = 0; k < N; k++) {
        alpha = (r | r) / (p | (A * p));
        x += (alpha * p);
        r_bis = r - (alpha * (A * p));
        rNorm = sqrt(r_bis|r_bis);
        
        printf("error : %f\n", rNorm);
        if (rNorm < eps)
        {
            return x;
        }

        beta = (r_bis | r_bis) / (r | r);
        p = r_bis + (beta * p);
        r = r_bis;
    }

    return x;
}
