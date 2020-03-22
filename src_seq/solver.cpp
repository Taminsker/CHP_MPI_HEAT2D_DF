#include "solver.h"

Vector conj_gradient (const Matrix &A, const Vector &b)
{
    int N = b.size ();

    if (N != (A.Nx * A.Ny)) return Vector (N, 0.);

    double eps = 1e-5;

    // Vector x (N, 0.);
    // Vector r = b;
    // Vector p = r;

    Vector x (N, 0.);
    Vector r = -1 * b;
    Vector p = -1 * r;

    print ("r", r);
    // return x;


    if (sqrt ((r | r)) < eps)
    {
        return x;
    }

    for (int k = 0; k < N; k++)
    {
        // printf ("(r|r)  = %f\n", (r | r));
        // printf ("(Ap|p)  = %f\n", ((A * p) | p));
        double alpha = (r | r) / ((p * A) | p);

        // printf ("alpha  = %f\n", alpha);

        x += alpha * p;

        Vector r_bis = r + (alpha * (A * p));

        printf ("error %.20f\n", sqrt ((r_bis | r_bis)));
        // print ("p", p, 9);
        if (sqrt ((r_bis | r_bis)) < eps)
        {
            return x;
        }

        double beta = (r_bis | r_bis) / (r | r);

        // printf ("(r2|r2)  = %f\n", (r_bis | r_bis));

        // printf ("beta  = %f\n\n", beta);

        p = - 1 * r_bis + beta * p;
        r = r_bis;
        // p *= beta;
        // p += r_bis;
    }

    // for (int k = 0; k < N; k++)
    // {
    //     // printf ("(r|r)  = %f\n", (r | r));
    //     // printf ("(Ap|p)  = %f\n", ((A * p) | p));
    //     double alpha = (r | r) / ((A * p) | p);
    //
    //     // printf ("alpha  = %f\n", alpha);
    //
    //     x += alpha * p;
    //
    //     Vector r_bis = r - (alpha * (A * p));
    //
    //     printf ("error %.20f\n", sqrt ((r_bis | r_bis)));
    //     // print ("p", p, 9);
    //     if (sqrt ((r_bis | r_bis)) < eps)
    //     {
    //         return x;
    //     }
    //
    //     double beta = (r_bis | r_bis) / (r | r);
    //
    //     // printf ("(r2|r2)  = %f\n", (r_bis | r_bis));
    //
    //     // printf ("beta  = %f\n\n", beta);
    //
    //     p = r_bis + beta * p;
    //     r = r_bis;
    //     // p *= beta;
    //     // p += r_bis;
    // }

    return x;
}
