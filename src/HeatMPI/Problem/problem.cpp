#include "problem.h"
#include "../ProcStruct/procstruct.h"

extern ProcStruct * MeProc;

Problem::Problem (std::string filename)
{
    // Lecture du fichier de paramètres
    std::string trash, variable;
    std::fstream paramFile (filename.c_str ());

    if (!paramFile.is_open ())
        printf ("Erreur lors de l'ouverture du fichier '%s'\n", filename.c_str ());

    // Récupère le Nx
    paramFile >> trash >> std::ws >> variable >> std::ws;
    Nx = size_t (std::stoi (variable));

    // Récupère le Ny
    paramFile >> trash >> std::ws >> variable >> std::ws;
    Ny = size_t (std::stoi (variable));

    // Récupère le Lx
    paramFile >> trash >> std::ws >> variable >> std::ws;
    Lx = std::stod (variable);

    // Récupère le Ly
    paramFile >> trash >> std::ws >> variable >> std::ws;
    Ly = std::stod (variable);

    // Récupère le D
    paramFile >> trash >> std::ws >> variable >> std::ws;
    D = std::stod (variable);

    // Récupère le dt
    paramFile >> trash >> std::ws >> variable >> std::ws;
    dt = std::stod (variable);

    paramFile.close ();
    // Fin de lecture

    dx = Lx / double (Nx - 1);
    dy = Ly / double (Ny - 1);

    b = - D / (dx * dx); // coeff pour i+1, et i-1
    c = - D / (dy * dy); // coeff pour j+1, et j-1
    a = 1. / dt - 2. * b - 2. * c; // coeff diagonal
}

Problem::~Problem ()
{}

void Problem::SetStationnary ()
{
    a = - 2. * b - 2. * c; // coeff diagonal
    return;
}

Vector operator* (const Vector &u, const Problem &A)
{
    return A * u;
}

Vector operator* (const Problem &A, const Vector &u)
{
    int Nx = int(A.Nx);
    int nproc = MeProc->nproc;
    int rank = MeProc->rank;
    size_t size = u.size ();

    // Ce qui sera le résultat de Au = v sur le proc courant
    Vector v (size, 0.);

    Vector precedent (size_t (Nx), 0.);// Le vecteur qui va recevoir les valeurs de x aux points sur la ligne au-dessous de iBeg
    Vector suivant (size_t (Nx), 0.); // Le vecteur qui va recevoir les valeurs de x aux points sur la ligne au-dessus de iEnd

    if (rank + 1 < nproc)
        MPI_Sendrecv( &u.at (size_t (size - Nx)), Nx, MPI_DOUBLE, rank + 1, 0,
                      &suivant.front(), Nx, MPI_DOUBLE, rank + 1, 0,
                      MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    if (rank - 1 >= 0)
        MPI_Sendrecv( &u.front(), Nx, MPI_DOUBLE, rank - 1, 0,
                      &precedent.front(), Nx, MPI_DOUBLE, rank - 1, 0,
                      MPI_COMM_WORLD, MPI_STATUS_IGNORE);


    int Ny = MeProc->NyLoc_end - MeProc->NyLoc_beg + 1;


    for (int j = 0; j < Ny; j++)
    {
        for (int i = 0; i < Nx; i++)
        {

            size_t idx = size_t (j * Nx + i);

            double* coeff = &v.at (size_t (idx));
            *coeff = 0.;

            if (j == 0) // en charge de me-1
                *coeff += A.c * precedent.at (size_t (i));
            else // en charge de me
                *coeff += A.c * u.at (idx - size_t(Nx));

            if (i != 0) // Si on n'est pas sur le bord gauche du maillage
                *coeff += A.b * u.at (idx - 1);

            *coeff += A.a * u.at (idx);

            if (i != Nx - 1) // Si on n'est pas sur le bord droit du maillage
                *coeff += A.b * u.at (idx + 1);

            if (j == Ny - 1) // en charge de me+1
                *coeff += A.c * suivant.at (size_t (i));
            else // en charge de me
                *coeff += A.c * u.at (idx + size_t(Nx));
        }
    }

    return v;
}
