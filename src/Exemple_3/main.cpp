#include <mpi.h>

#include "../HeatMPI/heat_mpi.h"
#include "listfunctions.h"


ProcStruct * MeProc = nullptr;

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    std::ofstream out ("Example_3.csv", std::ios::app);

    MPI_Init(&argc, &argv);
    double start = MPI_Wtime();


    Problem A ("params.dat");
    MeProc = new ProcStruct(&A);

    int size = MeProc->NyLoc_end - MeProc->NyLoc_beg + 1;
    Vector x (size_t (size)* A.Nx, 0.);
    Vector b = x;

    Vector b_01 = VectorBoundaryUpTop (g_3, A);
    b_01 += VectorBoundaryLeftRight (h_3, A);

//    createFileGnuplot (3, A);

    int maxStep = 30;

    for (int k = 0; k < maxStep; k++)
    {
        if (MeProc->rank == 0)
            printf("\rItération k : %i/%i \t ", k+1, maxStep);

        b = b_01;
        b += VectorSecondMember (f_3, k * A.dt, A);
        b += (1. / (A.dt)) * x;

        x = ConjuguateGradient (A, b);
        fflush(stdout);

//        printFile (3, x, A, k);
//        printFileGnuplot (3, k, "Solution numérique");
    }

//    endFileGnuplot (3);
//    fflush(stdout);

//    if (MeProc->rank == 0)
//    {
//        printf ("\nPour afficher : tapez 'gnuplot %s'\n", "script_test_3.gnu");
//    }

    if (MeProc->rank == 0)
    {
        double end = MPI_Wtime();
        out << end-start << " " << std::flush;
    }

    MPI_Finalize();
    delete MeProc;

    out.close ();
    return 0;
}
