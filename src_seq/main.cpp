#include <iostream>
#include <stdio.h>
#include "outputinput.h"
#include "solver.h"
#include "operators.h"
#include "matrix.h"
#include "listfunctions.h"
#include "secondmember.h"

#include <cstdlib>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    Matrix A;
    A.ReadParamFile ("param.dat");


    std::string gnuplot_file;
    std::string dat_file;

    Vector b (A.Nx * A.Ny, 0.);
    Vector x (A.Nx * A.Ny, 0.);

    bool NoBreak = true;

    while (NoBreak)
    {
        int casTest = 0;
        printf ("Cas test : \n");
        printf ("\t1 - Cas stationnaire polynomial\n");
        printf ("\t2 - Cas stationnaire sinusoidal\n");
        printf ("\t3 - Cas non stationnaire gaussien\n");
        printf ("Sortie : 0 - Sortie\n\n");
        printf ("Entrez numéro : ");
        scanf ("%i", &casTest);
        printf ("\n");

        switch (casTest)
        {
        case 1:
            {
                printf ("Cas stationnaire polynomial\n");
                gnuplot_file = "script_test_1.gnu";
                dat_file = "test1.dat";

                A.SetStationnaire ();
                b = Set_vector_f (f_1, 0., A);
                b += Set_vector_b0 (g_1, A);
                b += Set_vector_b1 (h_1, A);

                x = conj_gradient (A, b);

                printFile (dat_file, x, A);
                createFileGnuplot (gnuplot_file, A);
                printFileGnuplot (gnuplot_file, dat_file, 0, "Solution numérique");
                endFileGnuplot (gnuplot_file);


                printf ("Pour afficher : tapez 'gnuplot %s'\n", gnuplot_file.c_str ());

                break;
            }
        case 2:
            {
                printf ("Cas stationnaire sinusoidal\n");
                gnuplot_file = "script_test_2.gnu";
                dat_file = "test2.dat";

                A.SetStationnaire ();
                b = Set_vector_f (f_2, 0., A);
                b += Set_vector_b0 (g_2, A);
                b += Set_vector_b1 (h_2, A);

                x = conj_gradient (A, b);

                printFile (dat_file, x, A);
                createFileGnuplot (gnuplot_file, A);
                printFileGnuplot (gnuplot_file, dat_file, 0, "Solution numérique");
                endFileGnuplot (gnuplot_file);

                printf ("Pour afficher : tapez 'gnuplot %s'\n", gnuplot_file.c_str ());

                break;
            }

        case 3:
            {
                printf ("Cas non stationnaire gaussien\n");
                gnuplot_file = "script_test_3.gnu";

                Vector b_01 = Set_vector_b0 (g_3, A);
                b_01 += Set_vector_b1 (h_3, A);

                for (int k = 0; k < 100; k++)
                {
                    b = b_01;
                    b += Set_vector_f (f_3, k * A.dt, A);
                    b += (1. / (A.dt)) * x;

                    for (int k = 0; k < 250; k++)
                    {
                        printf("Itération k : %i \t- ", k);
                        b = b_01;
                        b += Set_vector_f (f_3, k * A.dt, A);
                        b += (1. / (A.dt)) * x;

                        dat_file = std::string ("test_3_") + std::to_string (k) + std::string (".dat");
                        printFile (dat_file, x, A);
                        printFileGnuplot (gnuplot_file, dat_file, k, "Solution numérique");
                    }

                    dat_file = std::string ("test_3_") + std::to_string (k) + std::string (".dat");
                    printFile (dat_file, x, A);
                    printFileGnuplot (gnuplot_file, dat_file, k, "Solution numérique");
                }

                endFileGnuplot (gnuplot_file);

                printf ("Pour afficher : tapez 'gnuplot %s'\n", gnuplot_file.c_str ());

                break;
            }
        default:
        case 0:
            printf ("Sortie du programme\n");
            NoBreak = false;
            break;
        }
    }

    return 0;
}
