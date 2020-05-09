#include "operators.h"
#include "../ProcStruct/procstruct.h"

extern ProcStruct * MeProc;

double operator| (const Vector &x, const Vector &y)
{
    if (x.size () != y.size ())
    {
        printf ("[%i] :: '|' les tailles sont differentes.\n", int (MeProc->rank));
        return -1.;
    }

    // Le produit scalaire partiel sur la tranche dont s'occupe le proc courant
    double ps = 0.;

    for (size_t i = 0; i < x.size () ; ++i)
    {
        ps += x.at (i) * y.at (i);
    }

    // Le produit scalaire total
    double ps_tot = 0.;

    // Chaque proc envoie sa part de ps_tot et reçoit celle des autres, pour avoir le ps_tot final
    MPI_Allreduce (&ps, &ps_tot, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

    return ps_tot;
}

Vector operator+ (const Vector &x, const Vector &y)
{
    if (x.size () != y.size ())
    {
        printf ("[%i] :: '+' les tailles sont differentes.\n", int (MeProc->rank));
        return Vector (x.size (), 0.);
    }

    Vector vec = x;
    return vec += y;
}

Vector operator- (const Vector &x, const Vector &y)
{
    if (x.size () != y.size ())
    {
        printf ("[%i] :: '-' les tailles sont differentes.\n", int (MeProc->rank));
        return Vector (x.size (), 0.);
    }

    Vector vec = x;
    return vec -= y;
}

Vector& operator+= (Vector &x, const Vector &y)
{
    if (x.size () != y.size ())
    {
        printf ("[%i] :: '+=' les tailles sont differentes. x(%i) y(%i)\n", int (MeProc->rank), int(x.size ()), int(y.size ()));
        return x;
    }

    for (size_t i = 0; i < x.size (); ++i)
    {
        x [i] += y [i];
    }

    return x;
}

Vector& operator-= (Vector &x, const Vector &y)
{
    if (x.size () != y.size ())
    {
        printf ("[%i] :: '-=' les tailles sont differentes.\n", int (MeProc->rank));
        return x;
    }

    for (size_t i = 0; i < x.size (); ++i)
    {
        x [i] -= y [i];
    }

    return x;
}

Vector operator* (double k, const Vector &x)
{
    Vector vec = x;
    return vec *= k;
}

Vector operator* (const Vector &x, double k)
{
    Vector vec = x;
    return vec *= k;
}

Vector& operator*= (Vector &x, double k)
{
    for (size_t i = 0; i < x.size (); ++i)
        x [i] *= k;

    return x;
}

