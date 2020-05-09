#include <mpi.h>

#include "../HeatMPI/heat_mpi.h"
#include "listfunctions.h"


ProcStruct * MeProc = nullptr;

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    std::ofstream out ("Example_2.csv", std::ios::app);

    MPI_Init(&argc, &argv);
    double start = MPI_Wtime();

    Problem A ("params.dat");
    MeProc = new ProcStruct(&A);

    Vector b, x;

    A.SetStationnary ();
    b = VectorSecondMember (f_2, 0., A);
    b += VectorBoundaryUpTop (g_2, A);
    b += VectorBoundaryLeftRight (h_2, A);

    x = ConjuguateGradient (A, b);

//    printFile (2, x, A, 0);
//    createFileGnuplot (2, A);
//    printFileGnuplot (2, 0, "Solution numérique");
//    endFileGnuplot (2);

//    double err_l2 = GetErrorl2 (u_ana2, x, A);

//    if (MeProc->rank == 0)
//    {
//        printf("\nErreur l2 : %f\n", err_l2);

//        printf ("Pour afficher : tapez 'gnuplot %s'\n", "script_test_2.gnu");
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
