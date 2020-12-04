#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <vector>

/// Struktura opisująca pojedynczy przedmiot i wszystkie oceny jego dotyczące
struct Subject
{
    /// Nazwa przedmiotu
    std::string subject;
    /// Wszystkie oceny z przedmiotu
    std::vector<float> rating;
};

/// Struktura opisująca pojedynczego studenta i jego wszystkie przedmioty
struct Student
{
    /// Imie i nazwisko studenta
    std::string name;
    /// Wszystkie przedmioty studenta wraz z ich ocenami
    std::vector<Subject> subject;
};


#endif STRUCTURES_H
