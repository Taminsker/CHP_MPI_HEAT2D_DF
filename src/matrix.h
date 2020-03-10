#ifndef MATRIX_HEAT_2D
#define MATRIX_HEAT_2D

#include <vector>

class Matrix
{
public:
    Matrix (int Nx, int Ny, double Lx, double Ly, double D, double dt);
    ~Matrix ();

    std::vector <double> GetMatrixLine (int i, int j);

private:
    double coef_a, coef_b, coef_c;
};



#endif // MATRIX_HEAT_2D
