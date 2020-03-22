#include <iostream>
#include <stdio.h>
#include "outputinput.h"
#include "solver.h"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    Param P = readParameters ("param.dat");

    printf("Nx = %d, Ny = %d, Lx = %f, Ly = %f, D = %f, dt = %f\n", P.Nx, P.Ny, P.Lx, P.Ly, P.D, P.dt);

    // INSTRUCTIONS POUR RESOUDRE LE VRAI PROBLEME

    //std::vector<double> u (5, 1);
    //std::vector<double> v (5, 3);
    //std::vector<double> w (5, 8);
    //std::vector<double> z (4, 2);

    //printf("(u|v) = %f\n", (u|v));

    //std::vector<double> a = u + v;

    //printf("u + v = \n");
    //for (int i = 0; i < a.size(); i++)
    //{
    //  printf("%f\n", a [i]);
    //}

    //std::vector<double> b = u - v;

    //printf("u - v = \n");
    //for (int i = 0; i < b.size(); i++)
    //{
    //  printf("%f\n", b [i]);
    //}

    //std::vector<double> c = 2.5*v;

    //print(c);

    return 0;
}
