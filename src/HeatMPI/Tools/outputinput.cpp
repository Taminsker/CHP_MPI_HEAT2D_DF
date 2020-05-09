#include "outputinput.h"

extern ProcStruct * MeProc;

void printFile (int exNum, const Vector &a, const Problem &A, int it)
{
    std::ofstream file ("example_" + std::to_string (exNum) + "_sol00" + std::to_string (MeProc->rank) + "_" + std::to_string (it) + ".dat");

    auto space = std::setw (20);
    file << "#X" << space << "Y" << space << "U" << std::endl;

    int Nx = int(A.Nx);
    int Ny = MeProc->NyLoc_end - MeProc->NyLoc_beg + 1;

    for (int j = 0; j < Ny; ++j)
    {
        for (int i = 0; i < Nx; ++i)
        {
            double x = double (i + 1) * A.dx;
            double y = double (j + MeProc->NyLoc_beg + 1) * A.dy;

            size_t index = size_t (j * Nx + i);

            file << double(x) << space << double(y) << space << double(a.at (index)) << std::endl;
        }
    }

    file.close ();
    return;
}

void createFileGnuplot (int exNum, const Problem& A)
{
    if (MeProc->rank == 0)
    {
        std::ofstream file ("script_test_" + std::to_string (exNum) + ".gnu");

        file << "reset" << std::endl;
        file << "xmax = " << A.Lx << std::endl;
        file << "xmin = 0.00000" << std::endl;
        file << "ymax = " << A.Lx << std::endl;
        file << "ymin = 0.00000" << std::endl;
        file << "dx = " << A.dx << std::endl;
        file << "dy = " << A.dy << std::endl << std::endl;

        file.close ();
    }

    MPI_Barrier (MPI_COMM_WORLD);

    return;
}

void printFileGnuplot (int exNum, int iteration, std::string categorie)
{
    if (MeProc->rank == 0)
    {
        std::ofstream file ("script_test_" + std::to_string (exNum) + ".gnu", std::ofstream::app);
        file << "sp [xmin-dx:xmax+dx][ymin-dy:ymax+dy] " << std::flush;

        for (int r = 0; r < MeProc->nproc; ++r)
        {
            std::string filename_dat = "example_" + std::to_string (exNum) + "_sol00" + std::to_string (r) + "_" + std::to_string (iteration) + ".dat";
            if (r != 0)
                file << ", ";
            file << "'" << filename_dat << "' t '#" << categorie << " " << iteration  << " proc " << r << "' w p palette" << std::flush;
        }

        file << "\npause 0.0001" << std::endl;

        file.close ();
    }

    MPI_Barrier (MPI_COMM_WORLD);

    return;
}


void endFileGnuplot (int exNum)
{
    if (MeProc->rank == 0)
    {
        std::ofstream file ("script_test_" + std::to_string (exNum) + ".gnu", std::ofstream::app);
        file << "pause -1" << std::endl;

        file.close ();
    }

    MPI_Barrier (MPI_COMM_WORLD);

    return;
}
