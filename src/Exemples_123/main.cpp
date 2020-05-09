#include <mpi.h>

#include "../HeatMPI/heat_mpi.h"
#include "listfunctions.h"


ProcStruct * MeProc = nullptr;

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    MPI_Init(&argc, &argv);

    Problem A ("params.dat");
    MeProc = new ProcStruct(&A);

    printf ("Me %i/%i, Nybeg %i, NyEnd %i\n", MeProc->rank+1, MeProc->nproc, MeProc->NyLoc_beg, MeProc->NyLoc_end);

    MPI_Barrier (MPI_COMM_WORLD);

    bool NoBreak = true;

    while (NoBreak)
    {
        int casTest = 0;

        if (MeProc->rank == 0)
        {
            printf ("\n---------------- MENU ---------------------\n");
            printf ("Cas test : \n");
            printf ("\t1 - Cas stationnaire polynomial\n");
            printf ("\t2 - Cas stationnaire sinusoidal\n");
            printf ("\t3 - Cas non stationnaire gaussien\n\n");
            printf ("\t0 - Sortie\n\n");
            printf ("Entrez numéro : ");
            std::cin >> casTest;
            printf ("\n");
        }

        MPI_Bcast (&casTest, 1, MPI_INT, 0, MPI_COMM_WORLD);

        switch (casTest)
        {
        case 1:
        {
            if (MeProc->rank == 0)
                printf ("Cas stationnaire polynomial\n");

            A = Problem("params.dat");
            delete MeProc;
            MeProc = new ProcStruct(&A);

            Vector b, x;

            A.SetStationnary ();
            b = VectorSecondMember (f_1, 0., A);
            b += VectorBoundaryUpTop (g_1, A);
            b += VectorBoundaryLeftRight (h_1, A);

            x = ConjuguateGradient (A, b);

            printFile (1, x, A, 0);
            createFileGnuplot (1, A);
            printFileGnuplot (1, 0, "Solution numérique");
            endFileGnuplot (1);

            double err_l2 = GetErrorl2 (u_ana1, x, A);

            if (MeProc->rank == 0)
            {
                printf("\nErreur l2 : %f\n", err_l2);

                printf ("Pour afficher : tapez 'gnuplot %s'\n", "script_test_1.gnu");
            }

            break;
        }
        case 2:
        {
            if (MeProc->rank == 0)
                printf ("Cas stationnaire sinusoidal\n");

            Problem A ("params.dat");
            delete MeProc;
            MeProc = new ProcStruct(&A);

            Vector b, x;

            A.SetStationnary ();
            b = VectorSecondMember (f_2, 0., A);
            b += VectorBoundaryUpTop (g_2, A);
            b += VectorBoundaryLeftRight (h_2, A);

            x = ConjuguateGradient (A, b);

            printFile (2, x, A, 0);
            createFileGnuplot (2, A);
            printFileGnuplot (2, 0, "Solution numérique");
            endFileGnuplot (2);

            double err_l2 = GetErrorl2 (u_ana2, x, A);
            if (MeProc->rank == 0)
            {
                printf("\nErreur l2 : %f\n", err_l2);

                printf ("Pour afficher : tapez 'gnuplot %s'\n", "script_test_2.gnu");
            }

            break;
        }

        case 3:
        {
            if (MeProc->rank == 0)
                printf ("Cas non stationnaire gaussien\n");

            Problem A ("params.dat");
            delete MeProc;
            MeProc = new ProcStruct(&A);

            int size = MeProc->NyLoc_end - MeProc->NyLoc_beg + 1;
            Vector x (size_t (size)* A.Nx, 0.);
            Vector b = x;

            Vector b_01 = VectorBoundaryUpTop (g_3, A);
            b_01 += VectorBoundaryLeftRight (h_3, A);

            createFileGnuplot (3, A);

            int maxStep = 100;
            if (MeProc->rank == 0)
            {
                printf("Combien d'étape maximum temps ? ");
                std::cin >> maxStep;
                printf ("\n");
            }
            MPI_Bcast (&maxStep, 1, MPI_INT, 0, MPI_COMM_WORLD);

            for (int k = 0; k < maxStep; k++)
            {
                if (MeProc->rank == 0)
                    printf("\rItération k : %i/%i \t ", k+1, maxStep);

                b = b_01;
                b += VectorSecondMember (f_3, k * A.dt, A);
                b += (1. / (A.dt)) * x;

                x = ConjuguateGradient (A, b);
                fflush(stdout);

                printFile (3, x, A, k);
                printFileGnuplot (3, k, "Solution numérique");
            }

            endFileGnuplot (3);
            fflush(stdout);

            if (MeProc->rank == 0)
            {
                printf ("\nPour afficher : tapez 'gnuplot %s'\n", "script_test_3.gnu");
            }

            break;
        }
        default:
        case 0:
            if (MeProc->rank == 0)
                printf ("Sortie du programme\n");
            NoBreak = false;
            break;
        }
    }



    MPI_Finalize();
    delete MeProc;

    return 0;

}
