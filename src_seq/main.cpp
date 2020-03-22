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

    // CAS TEST 1

    A.SetStationnaire ();

    Vector b = Set_vector_f (f_1, 0., A);
    b += Set_vector_b0 (g_1, A);
    b += Set_vector_b1 (h_1, A);

    Vector x = conj_gradient (A, b);

    printFile ("CasTest1.dat", x, A);

    return 0;
}
