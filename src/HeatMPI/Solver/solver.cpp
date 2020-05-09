#include "solver.h"

extern ProcStruct * MeProc;

Vector ConjuguateGradient (const Problem &A, const Vector &b)
{
    size_t N = b.size ();

    size_t Tot = A.Nx * A.Ny;
    double eps = 1e-10;

    Vector x (N, 0.);
    Vector r = b;
    Vector p = r;

    size_t k;
    for (k = 0; k < Tot; k++)
    {
        Vector Ap = A * p;

        double alpha = (r | r) / (Ap | p);

        x += alpha * p;

        Vector r_bis = r;
        r_bis -= alpha * Ap;

        double value = std::sqrt (r_bis|r_bis);

        if (value < eps)
        {
            r = r_bis;
            break;
        }

        double beta = (r_bis | r_bis) / (r | r);

        p *= beta;
        p += r_bis;
        r = r_bis;
    }

//    double value = std::sqrt (r|r);

//    if (MeProc->rank == 0)
//        printf ("(GradConj) : %i étapes", int(k));

    return x;
}


double GetErrorl2 (double (*u_ana) (double, double, double), const Vector& x, const Problem &A)
{
    int Nx = int(A.Nx);
    double error = 0.;

    int size = MeProc->NyLoc_end - MeProc->NyLoc_beg + 1;

    for (int j = 0; j < size; j++)
    {
        for (int i = 0; i < Nx; i++)
        {
            double value_num = x.at (size_t (j * Nx + i));
            double value_ana = u_ana ((i + 1) * A.dx, (j + MeProc->NyLoc_beg + 1.) * A.dy, 0);

            double delta_ij = value_num - value_ana;
            error += delta_ij * delta_ij;
        }
    }

    double error_tot = 0.;
    MPI_Allreduce (&error, &error_tot, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

    error_tot = sqrt(error_tot);
    error_tot *= (A.dx * A.dy);

    return error_tot;
}
