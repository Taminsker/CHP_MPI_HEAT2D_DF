#ifndef PROCSTRUCT_H
#define PROCSTRUCT_H

#include <mpi.h>

class Problem;
class ProcStruct
{
public:
    ProcStruct (Problem* problem);
    ~ProcStruct ();

    int rank;
    int nproc;
    int NyLoc_beg, NyLoc_end;

private:
    ProcStruct () = delete;
    ProcStruct (const ProcStruct& a) = delete;
};



#endif // PROCSTRUCT_H
