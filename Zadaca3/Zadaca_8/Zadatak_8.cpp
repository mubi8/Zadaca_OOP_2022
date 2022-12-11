#include "funkcije.hpp"
#include "strukture.hpp"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    short option;
    bool nastavak = true;
    std::list<Predmet> predmeti;
    std::vector<Student> studenti;
    while (nastavak)
    {
        try
        {
            menu(option);
            switch (option)
            {
            case 1:
            {
                predmeti.push_back(unesi_predmet(predmeti));
                break;
            }
            case 2:
            {
                studenti.push_back(unesi_studenta(predmeti, studenti));
                break;
            }
            case 3:
            {
                edit(predmeti,studenti);
                break;
            }
            case 4:
            {
                ispisi_studente(studenti);
                break;
            }
            case 5:
            {
                nastavak=false;
                break;
            }
            }
        }
        catch(const char* &e) {
            std::cout << e<< std::endl;
        }
    }
        return 0;
    }