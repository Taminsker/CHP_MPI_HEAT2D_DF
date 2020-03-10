#include <iostream>
#include <stdio.h>
#include "outputinput.h"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    Param P = readParameters ("param.dat");

    printf("Nx = %d, Ny = %d, Lx = %f, Ly = %f, D = %f, dt = %f\n", P.Nx, P.Ny, P.Lx, P.Ly, P.D, P.dt);

    return 0;
}
