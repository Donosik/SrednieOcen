#include "functions.h"

void Arguments(int argc, char *argv[], std::string &dataFile, bool &error)
{
    if (argc < 3) // Sprawdza czy liczba argumentów jest mniejsza niż 3, inaczej zatrzymuje aplikacje
    {
        std::cout << "Program do poprawnego dzialania wymaga uruchomienia z odpowiednimi przelacznikami:" << std::endl;
        std::cout << "-i plik wejsciowy z ocenami studentow" << std::endl;
        error = true;
        return;
    }
    for (int i = 1; i < argc; i += 2)
    {
        if ((std::string) argv[i] == "-i")
        {
            dataFile = argv[i + 1];
        }
    }
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
        Student student;
        student = StudentFromLine(line, error);
        if (error)
        {
            error = true;
            return students;
        }
        SaveStudent(students, student);
    }
    return students;
}

Student StudentFromLine(std::string line, bool &error)
{
    Student student;
    Subject subject;

    std::size_t found = line.find(',');
    if (found == std::string::npos)
    {
        std::cout << "1-Nieprawidlowy format pliku wejsciowego!" << std::endl;
        error = true;
        return student;
    }
    student.name = line.substr(0, found);

    std::size_t found2 = line.find(',', found + 1);
    if (found2 == std::string::npos)
    {
        std::cout << "2-Nieprawidlowy format pliku wejsciowego!" << std::endl;
        error = true;
        return student;
    }
    student.subject = std::vector<Subject>();
    subject.subject = line.substr(found + 1, found2 - found - 1);
    subject.rating = std::vector<float>();
    float rating = std::stof(line.substr(found2 + 1));

    subject.rating.push_back(rating);
    student.subject.push_back(subject);

    return student;
}

void SaveStudent(std::vector<Student> &students, Student student)
{
    bool isAdded = false;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].name == student.name)
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

void SaveData(std::vector<Student> &students, bool &error)
{
    for (int i = 0; i < students.size(); i++)
    {
        std::ofstream dataFile(students[i].name + ".csv");
        if (!dataFile.is_open())
        {
            error = true;
            return;
        }
        for (int j = 0; j < students[i].subject.size(); j++)
        {
            dataFile << students[i].subject[j].subject << ", ";
            float average = 0;
            for (int k = 0; k < students[i].subject[j].rating.size(); k++)
            {
                average += students[i].subject[j].rating[k];
            }
            average = average / students[i].subject[j].rating.size();
            dataFile << std::setprecision(3) << average << std::endl;
        }
    }
}