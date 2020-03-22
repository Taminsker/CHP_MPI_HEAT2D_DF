#include "matrix.h"

Matrix::Matrix ()
{}

void Matrix::ReadParamFile (std::string filename)
{
    // Lecture du fichier de paramètres
    std::string trash, variable;
    std::fstream paramFile (filename.c_str ());

    // Récupère le Nx
    paramFile >> trash >> std::ws >> variable >> std::ws;
    Nx = std::stoi (variable);

    // Récupère le Ny
    paramFile >> trash >> std::ws >> variable >> std::ws;
    Ny = std::stoi (variable);

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

    dx = Lx / double (Nx);
    dy = Ly / double (Ny);

    coeff_b = - D / (dx * dx); // coeff pour i+1, et i-1
    coeff_c = - D / (dy * dy); // coeff pour j+1, et j-1
    coeff_a = 1. / dt - 2. * coeff_b - 2. * coeff_c; // coeff diagonal

    return;
}

void Matrix::SetStationnaire ()
{
    coeff_a = - 2. * coeff_b - 2. * coeff_c; // coeff diagonal
    return;
}



Matrix::~Matrix ()
{}

Vector operator* (const Vector &x, const Matrix &A)
{
    return A * x;
}

Vector operator* (const Matrix &A, const Vector &x)
{
    if (x.size () != (A.Nx * A.Ny)) return Vector (x.size (), 0.);

    Vector b (x.size (), 0.);

    for (int j = 0; j < A.Ny; j++) {
        for (int i = 0; i < A.Nx; i++) {

            int index = j * A.Nx + i;

            // contribution du pt_(i, j-1)
            b [index] += (j > 0 ? A.coeff_c * x [index - A.Nx] : 0.);

            // contribution du pt_(i-1, j)
            b [index] += (i > 0 ? A.coeff_b * x [index - 1]: 0.);

            // contribution du pt_(i, j)
            b [index] += A.coeff_a * x [index];

            // contribution du pt_(i+1, j)
            b [index] += (i + 1 < A.Nx ? A.coeff_b * x [index + 1] : 0.);

            // contribution du pt_(i, j+1)
            b [index] += (j + 1 < A.Ny ? A.coeff_c * x [index + A.Nx] : 0.);
        }
    }
    return b;
}

void print (std::string name, const Matrix &A, int infr, int supr, int infc, int supc)
{
    supr = (supr < 1 ? A.Ny * A.Nx -1 : supr);
    supr = (supr > A.Nx * A.Ny ? A.Ny * A.Nx -1 : supr);
    infr = (infr > A.Nx * A.Ny ? 0 : infr);

    if (supr <= infr) return;

    supc = (supc < 1 ? A.Ny * A.Nx -1 : supc);
    supc = (supc > A.Nx * A.Ny ? A.Ny * A.Nx -1 : supc);
    infc = (infc > A.Nx * A.Ny ? 0 : infc);

    if (supc <= infc) return;

    if (name != "")
    {
        printf ("%s ([%d:%d] x [%d:%d]) = \n", name.c_str (), infr, supr, infc, supc);
    }

    for (int j = 0; j < A.Ny; j++)
    {
        for (int i = 0; i < A.Nx; i++)
        {
            int index = j * A.Nx + i;

            if (index >= infr && index <= supr)
            {
                for (size_t k = infc; k <= supc; k++) // Boucle sur les coeffs de la ligne index
                {
                    if (k == index)
                    {
                        printf ("\033[0;31m%+10.2f\033[0m ", A.coeff_a);
                    }
                    else if (index + 1 == k && i < A.Nx - 1)
                    {
                        printf ("\033[0;35m%+10.2f\033[0m ", A.coeff_b);
                    }
                    else if (index - 1 == k && i > 0)
                    {
                        printf ("\033[0;35m%+10.2f\033[0m ", A.coeff_b);
                    }
                    else if (index + A.Nx == k && j < A.Ny - 1)
                    {
                        printf ("\033[0;32m%+10.2f\033[0m ", A.coeff_c);
                    }
                    else if (index - A.Nx == k && j > 0)
                    {
                        printf ("\033[0;32m%+10.2f\033[0m ", A.coeff_c);
                    }
                    else
                    {
                        printf ("%10.1i ", 0);
                    }
                }

                // if (supr != A.Nx * A.Ny -1)
                // {
                //     printf (" ... [%i]", A.Nx * A.Ny);
                // }
                printf("\n");
            }
        }
    }
    return;
}
