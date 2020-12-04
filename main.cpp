#include "functions.h"

int main(int argc, char *argv[])
{
    /// Zmienna w której przechowywana jest nazwa pliku ze studentami
    std::string dataFileName;
    /// Zmienna kontrolująca czy funckje wykonują się poprawnie jak należy
    bool error = false;

    Arguments(argc, argv, dataFileName, error);
    // Sprawdzenie czy funckja się wykonała poprawnie
    if (error)
    {
        return 0;
    }

    /// Zmienna zawierająca dane wszystkich studentów
    std::vector<Student> students;
    students = DataInput(dataFileName, error);
    // Sprawdzenie czy funckja się wykonała poprawnie
    if (error)
    {
        return 0;
    }

    SaveData(students, error);
    // Sprawdzenie czy funckja się wykonała poprawnie
    if (error)
    {
        return 0;
    }

    return 0;
}
