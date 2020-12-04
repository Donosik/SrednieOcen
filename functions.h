#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "structures.h"

void Arguments(int argc, char *argv[], std::string &dataFileName, bool &error);

std::vector<Student> DataInput(std::string dataFileName, bool &error);

Student StudentFromLine(std::string line,bool &error);

void SaveStudent(std::vector<Student> &students,Student student);

void SaveData(std::vector<Student> &students, bool &error);

#endif FUNCTIONS_H
