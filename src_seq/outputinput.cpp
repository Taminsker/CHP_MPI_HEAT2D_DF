#include "outputinput.h"


void printFile (std::string filename, const Vector &a, const Matrix &A)
{
    std::ofstream file (filename.c_str ());

    auto space = std::setw (20);
    file << "#X" << space << "Y" << space << "U" << std::endl;

    double dx = A.Lx / double (A.Nx);
    double dy = A.Ly / double (A.Ny);

    int Nx = A.Nx;
    int Ny = A.Ny;

    for (int i = 0; i < Nx; ++i)
    {
        for (int j = 0; j < Ny; ++j)
        {
            double x = i * dx;
            double y = j * dy;

            int index = j * Nx + i;

            file << x << space << y << space << a [index] << std::endl;
        }
    }

    file.close ();

    return;
}
