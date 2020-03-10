#ifndef OUTPUTINPUT_H
#define OUTPUTINPUT_H

#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstring>

struct Param
{
  int Nx, Ny;
  double Lx, Ly, D, dt;
};

Param readParameters (std::string filename = "param.dat");

#endif // OUTPUTINPUT_H
