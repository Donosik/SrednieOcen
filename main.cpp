#include "functions.h"

int main(int argc, char *argv[])
{
    std::string dataFileName;
    if (!Arguments(argc, argv, dataFileName))
    {
        return 1;
    }
    bool error = false;
    std::vector<Student> students = DataInput(dataFileName, error);
    if (error)
    {
        return 2;
    }
    /*
    //Do wyświetlania
    for (int i = 0; i < students.size(); i++)
    {
        std::cout << students[i].firstName << " " << students[i].lastName << std::endl;
        for (int j = 0; j < students[i].subject.size(); j++)
        {
            std::cout << students[i].subject[j].subject << " ";
            for (int k = 0; k < students[i].subject[j].rating.size(); k++)
            {
                std::cout << students[i].subject[j].rating[k] << " ";
            }
            std::cout << std::endl;
        }
    }
     */
    return 0;
}
