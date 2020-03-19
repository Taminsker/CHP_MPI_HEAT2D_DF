#include "outputinput.h"

Param readParameters (std::string filename)
{
  Param parameters;
  std::string none, var;

  std::fstream file (filename.c_str());

  file >> none >> std::ws >> var >> std::ws;
  parameters.Nx = std::stoi (var);

  file >> none >> std::ws >> var >> std::ws;
  parameters.Ny = std::stoi (var);

  file >> none >> std::ws >> var >> std::ws;
  parameters.Lx = std::stod (var);

  file >> none >> std::ws >> var >> std::ws;
  parameters.Ly = std::stod (var);

  file >> none >> std::ws >> var >> std::ws;
  parameters.D = std::stod (var);

  file >> none >> std::ws >> var >> std::ws;
  parameters.dt = std::stod (var);

  file.close ();

  return parameters;
}
