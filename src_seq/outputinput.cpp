#include "outputinput.h"


void printFile (std::string filename, const Vector &a, const Matrix &A)
{
    std::ofstream file (filename.c_str ());

    auto space = std::setw (20);
    file << "#X" << space << "Y" << space << "U" << std::endl;

    for (int i = 0; i < A.Nx; ++i)
    {
        for (int j = 0; j < A.Ny; ++j)
        {
            double x = i * A.dx;
            double y = j * A.dy;

            int index = j * A.Nx + i;

            file << x << space << y << space << a [index] << std::endl;
        }
    }
    file.close ();
    return;
}

void createFileGnuplot (std::string filename, const Matrix& A)
{
    std::ofstream file (filename.c_str ());

    file << "reset" << std::endl;
    file << "xmax = " << A.Lx << std::endl;
    file << "xmin = 0.00000" << std::endl;
    file << "ymax = " << A.Lx << std::endl;
    file << "ymin = 0.00000" << std::endl;
    file << "dx = " << A.dx << std::endl;
    file << "dy = " << A.dy << std::endl << std::endl;

    file.close ();
}

void printFileGnuplot (std::string filename_gnu, std::string filename_dat, int iteration, std::string categorie)
{
    std::ofstream file (filename_gnu.c_str (), std::ofstream::app);

    file << "sp [xmin-dx:xmax+dx][ymin-dy:ymax+dy] '" << filename_dat << "' t '#" << categorie << " " << iteration << "' w p palette" << std::endl;
    file << "pause 0.0001" << std::endl;

    file.close ();
}

void endFileGnuplot (std::string filename)
{
    std::ofstream file (filename.c_str (), std::ofstream::app);
    file << "pause -1" << std::endl;

    file.close ();
}
