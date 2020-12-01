#include "functions.h"

bool Arguments(int argc, char *argv[], std::string &dataFile)
{
    if (argc < 3) // Sprawdza czy liczba argumentów jest mniejsza niż 3, inaczej zatrzymuje aplikacje
    {
        std::cout << "Program do poprawnego dzialania wymaga uruchomienia z odpowiednimi przelacznikami:" << std::endl;
        std::cout << "-i plik wejsciowy z ocenami studentow" << std::endl;
        return false;
    }
    for (int i = 1; i < argc; i += 2)
    {
        if ((std::string) argv[i] == "-i")
        {
            dataFile = argv[i + 1];
        }
    }
    return true;
}

std::vector<Student> DataInput(std::string dataFileName, bool &error)
{
    std::ifstream file(dataFileName);
    std::vector<Student> students;
    if (!file.is_open())
    {
        std::cout << "Plik zostal nieprawidlowo wczytany" << std::endl;
        error = true;
        return students;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        char trash;
        Student student;
        std::string x, y;
        ss >> student.firstName >> x >> y;
        std::size_t found = x.find(',');
        if (found == std::string::npos)
        {
            std::cout << "Nieprawidlowy format pliku wejsciowego!" << std::endl;
            error = true;
            return students;
        }
        student.lastName = x.substr(0, found);
        student.subject = std::vector<Subject>();
        Subject subject;
        subject.subject = x.substr(found + 1);
        found = y.find(',');
        if (found == std::string::npos)
        {
            std::cout << "Nieprawidlowy format pliku wejsciowego!" << std::endl;
            error = true;
            return students;
        }
        subject.subject += " ";
        subject.subject += y.substr(0, found);
        subject.rating = std::vector<float>();
        float rating = std::stof(y.substr(found + 1));
        subject.rating.push_back(rating);
        student.subject.push_back(subject);
        bool isAdded = false;
        for (int i = 0; i < students.size(); i++)
        {
            if ((students[i].firstName == student.firstName) && (students[i].lastName == student.lastName))
            {
                for (int j = 0; j < students[i].subject.size(); j++)
                {
                    if (students[i].subject[j].subject == student.subject[0].subject)
                    {
                        students[i].subject[j].rating.push_back(student.subject[0].rating[0]);
                        isAdded = true;
                        break;
                    }

                }
                if (!isAdded)
                {
                    students[i].subject.push_back(student.subject[0]);
                    isAdded = true;
                    break;
                }
            }
        }
        if (!isAdded)
        {
            students.push_back(student);
            isAdded = true;
        }
    }

    return students;
}