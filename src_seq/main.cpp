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

    int N = 4;

    Vector u (N, 2);
    Vector v (N, -3);
    Vector w (N, 4.5);

    print ("u", u);
    print ("v", v);
    print ("w", w);

    printf ("u|v = %f\n", (u|v));
    print ("u+v", u+v);
    print ("u-v", u-v);
    print ("u+v", u+v);
    print ("2.5 * u", 2.5 * u);

    w = u+v;
    print ("u+v", w);
    w += w;
    print ("2*(u+v)", w);
    w *= 0.5;
    print ("u+v", w);


    return 0;

    // CAS TEST 1

    A.SetStationnaire ();

    Vector b = Set_vector_f (f_1, 0., A);
    print ("f", Set_vector_f (f_1, 0., A));
    print ("g", Set_vector_b0 (g_1, A));
    print ("h", Set_vector_b1 (h_1, A));

    b += Set_vector_b0 (g_1, A);
    b += Set_vector_b1 (h_1, A);

    Vector x = conj_gradient (A, b);

    printFile ("CasTest1.dat", x, A);

    return 0;
}
