#ifndef OUTPUTINPUT_H
#define OUTPUTINPUT_H

#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

#include "matrix.h"
#include "operators.h"

void printFile (std::string filename, const Vector &a, const Matrix &A);
void createFileGnuplot (std::string filename, const Matrix& A);
void printFileGnuplot (std::string filename_gnu, std::string filename_dat, int iteration, std::string categorie);
void endFileGnuplot (std::string filename);

#endif // OUTPUTINPUT_H
