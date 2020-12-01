#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "structures.h"

bool Arguments(int argc, char *argv[],std::string& dataFileName);

std::vector<Student> DataInput(std::string dataFileName,bool& error);

#endif FUNCTIONS_H
