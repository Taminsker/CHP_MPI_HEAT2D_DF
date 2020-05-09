#include <mpi.h>

#include "../HeatMPI/heat_mpi.h"
#include "listfunctions.h"


ProcStruct * MeProc = nullptr;

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    std::ofstream out ("Example_1.csv", std::ios::app);

    MPI_Init(&argc, &argv);
    double start = MPI_Wtime();

    Problem A ("params.dat");
    MeProc = new ProcStruct(&A);

    Vector b, x;

    A.SetStationnary ();
    b = VectorSecondMember (f_1, 0., A);
    b += VectorBoundaryUpTop (g_1, A);
    b += VectorBoundaryLeftRight (h_1, A);

    x = ConjuguateGradient (A, b);

//    printFile (1, x, A, 0);
//    createFileGnuplot (1, A);
//    printFileGnuplot (1, 0, "Solution numérique");
//    endFileGnuplot (1);

//    double err_l2 = GetErrorl2 (u_ana1, x, A);

//    if (MeProc->rank == 0)
//    {
//        printf("\nErreur l2 : %f\n", err_l2);

//        printf ("Pour afficher : tapez 'gnuplot %s'\n", "script_test_1.gnu");
//    }

//    if (MeProc->rank == 0)
//    {
//        double end = MPI_Wtime();
//        out << end-start << " " << std::flush;
//    }

    printf ("[%i] time : %f\n", MeProc->rank, MPI_Wtime () - start);

    MPI_Finalize();
    delete MeProc;

    out.close ();
    return 0;

}
