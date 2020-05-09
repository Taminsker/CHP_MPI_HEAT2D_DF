#ifndef OUTPUTINPUT_H
#define OUTPUTINPUT_H

#include <sstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

#include "../Problem/problem.h"
#include "../ProcStruct/procstruct.h"
#include "operators.h"

void printFile (int exNum, const Vector &a, const Problem &A, int it)
;
void createFileGnuplot (int exNum, const Problem& A);

void printFileGnuplot (int exNum, int iteration, std::string categorie);

void endFileGnuplot (int exNum);
#endif // OUTPUTINPUT_H
