#include "secondmember.h"

extern ProcStruct * MeProc;

Vector VectorBoundaryUpTop (double (*f) (double, double, double), const Problem &A)
{
    int Nx = int(A.Nx);

    int size = MeProc->NyLoc_end - MeProc->NyLoc_beg + 1;
    Vector vec(size_t (size * Nx), 0.);

    for (int i = 0; i < Nx; i++)
    {
        for (int j : {MeProc->NyLoc_beg, MeProc->NyLoc_end})
        {
            if (j == 0)
            {
//                printf (\"(UT) Me : %i, impose node %i\n", MeProc->rank,i);
                vec.at (size_t (i)) = f ((i + 1) * A.dx, 0., 0.);
            }

            if (j == int(A.Ny - 1))
            {
//                printf ("(UT) Me : %i, impose node %i\n", MeProc->rank,(size - 1) * Nx + i);

                vec.at (size_t ((size - 1) * Nx + i)) = f ((i + 1) * A.dx, A.Ly, 0.);
            }
        }
    }

    vec *= -A.c;

    return vec;
}

Vector VectorBoundaryLeftRight (double (*f) (double, double, double), const Problem &A)
{
    int Nx = int(A.Nx);

    int size = MeProc->NyLoc_end - MeProc->NyLoc_beg + 1;
    Vector vec(size_t (size * Nx), 0.);

    for (int j = 0; j < size; ++j)
    {
//        printf ("(RL) Me : %i, impose node %i\n", MeProc->rank, j * Nx + 0);

        vec.at (size_t (j * Nx) + 0) = f (0., (j + MeProc->NyLoc_beg + 1) * A.dy, 0.);

//        printf ("(RL) Me : %i, impose node %i\n", MeProc->rank, j * Nx + (Nx - 1));

        vec.at (size_t (j * Nx + (Nx - 1))) = f (A.Lx, (j + MeProc->NyLoc_beg + 1) * A.dy, 0.);
    }

    vec *= -A.b;

    return vec;
}

Vector VectorSecondMember (double (*f) (const Problem&, double, double, double), double t, const Problem &A)
{
    int Nx = int(A.Nx);

    int size = MeProc->NyLoc_end - MeProc->NyLoc_beg + 1;
    Vector vec(size_t (size * Nx), 0.);

    for (int j = 0; j < size; ++j)
    {
        for (int i = 0; i < Nx; ++i)
        {
            vec.at (size_t (j * Nx + i)) = f (A, (i + 1) * A.dx, (j + MeProc->NyLoc_beg + 1) * A.dy, t);
        }
    }

    return vec;
}
