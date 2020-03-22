#include <iostream>
#include <stdio.h>
#include "outputinput.h"
#include "solver.h"
#include "operators.h"
#include "matrix.h"
#include "listfunctions.h"

#include <cstdlib>

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    Matrix A;
    A.ReadParamFile ("param.dat");


    // TESTS
    // int N = A.Nx * A.Ny;
    //
    // Vector b (N, 0.);
    //
    // for (int i = 0; i < A.Nx; ++i)
    // {
    //     for (int j = 0; j < A.Ny; ++j)
    //     {
    //         b [j * A.Nx + i] = f_1 (i * A.dx, j * A.dy);
    //     }
    // }
    //
    //
    // // Vector a (N, 0.5);
    // // printFile ("test.dat", A * a, A);
    // // print ("b", b, 9);
    //
    // // print ("A", A, 0, 10, 0, 10);
    //
    //
    // Vector x;
    // x = conj_gradient (A, b);
    //
    // // print ("x", x, 9);
    //
    //
    // printFile ("test.dat", x, A);
    //
    //
    // return 0;

    // TESTS
    int N = 10000;

    Vector u (N, 1);
    Vector v (N, 3);
    Vector w (N, 8);
    Vector z (N, 2);

    print ("u", u);
    print ("v", v);
    print ("w", w);
    print ("z", z);

    printf ("u|v = %f\n", u|v);
    print ("u+v", u+v);
    print ("u-v", u-v);
    print ("2.5 * u", 2.5 * u);
    //
    // // Matrix A;
    // // A.ReadParamFile ();
    // // print ("A", A, 0, 10, 250, 260); // affiche A (0:10, 250,260)
    //
    // // print ("A", A); // affiche A (0:10, 250,260)
    //
    // /// Exemple écriture de fichiers
    // Vector vec (A.Nx * A.Ny, 1.);
    // print ("vec", vec, 9);
    //
    // vec = A * vec;
    //
    // print ("vec", vec, 9);

    // for (int i = 0; i < A.Nx; ++i)
    // {
    //     for (int j = 0; j < A.Ny; ++j)
    //     {
    //         double x = i * A.dx;
    //         double y = j * A.dy;
    //
    //         int index = j * Nx + i;
    //
    //         vec [index] = x*x + y*y;
    //     }
    // }

    // printFile ("test.dat", vec, A);

    return 0;
}
