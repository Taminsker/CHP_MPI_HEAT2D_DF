#include "operators.h"

double operator| (Vector x, Vector y)
{
    if (x.size () != y.size ()) return -1.;

    double ps = 0;

    for (size_t i = 0; i <= x.size () ; ++i)
    {
        ps += x [i] * y [i];
    }

    return ps;
}


Vector operator+ (const Vector &x, const Vector &y)
{
    if (x.size () != y.size ()) return Vector (1, -1.);

    Vector vec = x;
    return vec += y;
}


Vector operator- (const Vector &x, const Vector &y)
{
    if (x.size () != y.size ()) return Vector (1, -1.);

    Vector vec = x;
    return vec -= y;
}


Vector& operator+= (Vector &x, const Vector &y)
{
    if (x.size () != y.size ()) return x;

    for (size_t i = 0; i < x.size (); ++i)
    {
        x [i] += y [i];
    }

    return x;
}


Vector& operator-= (Vector &x, const Vector &y)
{
    if (x.size () != y.size ()) return x;

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
    {
        x [i] *= k;
    }

    return x;
}

void print (std::string name, Vector a, size_t dispSize)
{
    if (name != "")
    printf ("%s = ", name.c_str ());

    for (size_t i = 0; i < a.size() && i < dispSize; i++)
    printf("%f ", a [i]);

    if (a.size () > dispSize)
    printf (" ... [%i]", a.size ());
    printf("\n");

    return;
}
