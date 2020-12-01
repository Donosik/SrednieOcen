#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <vector>

struct Subject
{
    std::string subject;
    std::vector<float> rating;
};

struct Student
{
    std::string firstName;
    std::string lastName;
    std::vector<Subject> subject;
};


#endif STRUCTURES_H
