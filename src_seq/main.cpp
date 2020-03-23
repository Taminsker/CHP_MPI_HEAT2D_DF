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

    int casTest = 0;
    printf ("Cas test 1, 2 ou 3 : \n");
    scanf ("%d\n", &casTest);

    switch (casTest)
    {
    case 1:
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


        printf ("Pour afficher : tapez 'gnuplot' puis\n'splot using 1:2:3 w p palette'");

        break;

    case 2:
        printf ("Cas stationnaire sinusoidal\n");
        gnuplot_file = "script_test_2.gnu";
        dat_file = "test2.dat";

        A.SetStationnaire ();
        b = Set_vector_f (f_2, 0., A);
        b += Set_vector_b0 (g_2, A);
        b += Set_vector_b1 (h_2, A);

        x = conj_gradient (A, b);
        printFile ("sol.dat", x, A);

        printFile (dat_file, x, A);
        createFileGnuplot (gnuplot_file, A);
        printFileGnuplot (gnuplot_file, dat_file, 0, "Solution numérique");
        endFileGnuplot (gnuplot_file);

        printf ("Pour afficher : tapez 'gnuplot' puis\n'splot using 1:2:3 w p palette'");

        break;

    case 3:
        printf ("Cas non stationnaire gaussien\n");

        b = Set_vector_f (f_3, 0., A);
        b += Set_vector_b0 (g_3, A);
        b += Set_vector_b1 (h_3, A);

        x = conj_gradient (A, b);
        printFile ("sol.dat", x, A);

        printf ("Pour afficher : tapez 'gnuplot' puis\n'splot using 1:2:3 w p palette'");

        break;
    }

    return 0;
}
