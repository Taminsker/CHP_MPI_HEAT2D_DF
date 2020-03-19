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

#endif // OUTPUTINPUT_H
