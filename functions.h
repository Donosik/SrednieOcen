#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "structures.h"

/// Funkcja, która przyjmuje parametry programu i przypisuje do odpowiednich zmiennych odpowiednie wartosci
/// @param argc Ilość argumentów otrzymanych przez program, przekazane z funkcji main
/// @param argv Tablica argumentów otrzymanych przez program, przekazane z funkcji main
/// @param dataFileName Referencja do zmienniej zawierającej nazwe pliku wejsciowego
/// @param error Referencja do zmiennej używanej do zwracania, gdy funkcja natrafi na błąd
void Arguments(int argc, char *argv[], std::string &dataFileName, bool &error);

/// Funkcja wczytująca wszystkich studentów do wektora i zwracająca jego wartosc
/// @param dataFileName Nazwa pliku z którego funkcja ma odczytywać dane
/// @param error Referencja do zmiennej używanej do zwracania, gdy funkcja natrafi na błąd
/// @return Wektor struktury studentów wczytanych z pliku przez funkcję
std::vector<Student> DataInput(std::string dataFileName, bool &error);

/// Funkcja wczytująca z pojedynczej linii studenta i zapisująca go do struktury student
/// @param line String, z którego funckja ma wyczytać dane
/// @param error Referencja do zmiennej używanej do zwracania, gdy funkcja natrafi na błąd
/// @return
Student StudentFromLine(std::string line,bool &error);

/// Funkcja dodająca studenta do wektora wszystkich studentów
/// @param students Referencja do wektora wszystkich studentów
/// @param student Student, który ma być dodany do wektora
void AddStudent(std::vector<Student> &students, Student student);

/// Funkcja zapisujaca wszystkich studentów do odpowiednich plików wraz z przedmiotami i ocenami
/// @param students Wektor wszystkich studentów, którzy będą zapisani do plików
/// @param error Referencja do zmiennej używanej do zwracania, gdy funkcja natrafi na błąd
void SaveData(std::vector<Student> &students, bool &error);

#endif FUNCTIONS_H
