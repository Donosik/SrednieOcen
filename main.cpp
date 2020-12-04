#include "functions.h"

int main(int argc, char *argv[])
{
    std::string dataFileName;
    bool error = false;
    Arguments(argc, argv, dataFileName, error);
    if (error)
    {
        return 0;
    }
    std::vector<Student> students = DataInput(dataFileName, error);
    if (error)
    {
        return 0;
    }
    SaveData(students, error);
    if (error)
    {
        return 0;
    }
    return 0;
}
