#include "procstruct.h"
#include "../Problem/problem.h"

ProcStruct::ProcStruct (Problem* problem)
{
    MPI_Comm_size (MPI_COMM_WORLD, &nproc);
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);

    int NyGlobal = int(problem->Ny);

    int value = NyGlobal%nproc;
    NyLoc_beg = rank * (NyGlobal / nproc) + std::min (rank, value);
    NyLoc_end = NyLoc_beg  + (NyGlobal / nproc) - static_cast<int> (rank >= value);
}

ProcStruct::~ProcStruct ()
{}
