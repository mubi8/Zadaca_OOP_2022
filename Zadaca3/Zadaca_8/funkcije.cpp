#include "strukture.hpp"
#include <iostream>
#include <string>

Predmet unesi_predmet(std::list<Predmet> &predmeti)
{
    std::string naziv;
    std::cout << "Unesi naziv predmeta: ";
    std::getline(std::cin, naziv);
    for (auto &predmet : predmeti)
    {
        if (naziv == predmet.naziv)
        {
            throw "Uneseni predmet vec postoji!";
        }
    }

    std::string odsjek;
    std::cout << "Unesite odsjek: ";
    std::getline(std::cin, odsjek);
    std::cout << std::endl;
    return {naziv, odsjek};
}

std::vector<OcjenaIzPredmeta> unesi_ocjene(std::list<Predmet> &predmeti,
                                           std::vector<Student> &studenti)
{

    std::vector<OcjenaIzPredmeta> ocjene;

    short broj_ocjena;
    do
    {
        std::cout << "Unesite koliko zelite ocjena unijeti: ";
        std::cin >> broj_ocjena;
        if (broj_ocjena < 0)
        {
            std::cout << "Uneseni broj ocjena ne smije biti manji od 0!" << std::endl;
        }
    } while (broj_ocjena < 0);

    std::cin.ignore();
    while (broj_ocjena)
    {
        OcjenaIzPredmeta novaOcjena;
        std::string naziv;
        std::cout << "Unesite naziv predmeta: ";
        std::getline(std::cin,naziv);
        auto it = predmeti.cbegin();
        while (it != predmeti.cend())
        {
            if (naziv == it->naziv)
            {
                novaOcjena.predmet = it;
                break;
            }
            it++;
        }
        if (it == predmeti.cend())
        {
            std::cout << "Uneseni predmet ne postoji!"<<std::endl;
            --broj_ocjena;
            //ocjene.push_back(novaOcjena);
            continue;
        }
        else
        {
            int unesenaOcjena;
            do
            {
                std::cout << "Unesite ocjenu: ";
                std::cin >> unesenaOcjena;
                std::cin.ignore();
                if (unesenaOcjena < 5 || unesenaOcjena > 10)
                {
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "Unesena ocjena ne smije biti manja od 5 niti veca od 10" << std::endl;
                }
            } while (unesenaOcjena < 5 || unesenaOcjena > 10);
            novaOcjena.ocjena = unesenaOcjena;
            std::cout << '\n';
        }
        ocjene.push_back(novaOcjena);
        --broj_ocjena;
    }

    return ocjene;
}

Student unesi_studenta(std::list<Predmet> &predmeti,
                       std::vector<Student> &studenti)
{
    Student noviStudent;
    std::cout << "Unesi broj indeksa: ";
    std::cin >> noviStudent.brojIndeksa;
    for (auto &e : studenti)
    {
        if (noviStudent.brojIndeksa == e.brojIndeksa)
        {
            throw "Student sa datim brojem indeksa vec postoji!";
        }
    }
    std::cin.ignore();
    std::cout << "Unesite ime: ";
    std::getline(std::cin, noviStudent.ime);

    std::cout << "Unesite prezime: ";
    std::getline(std::cin, noviStudent.prezime);

    // std::string grad;
    std::cout << "Unesite grad: ";
    std::getline(std::cin, noviStudent.grad);
    noviStudent.ocjene = unesi_ocjene(predmeti, studenti);
    return noviStudent;
}

void ispisi_studente(std::vector<Student> &studenti)
{
    if (studenti.empty())
    {
        std::cout << "Nema nijednog studenta";
    }
    else
    {
        for (auto &e : studenti)
        {
            std::cout << "Ime i prezime: " << e.ime << " " << e.prezime << std::endl;
            std::cout << "Grad: " << e.grad << std::endl;
            std::cout << "Ocjene: " << std::endl;
            for (auto &ocjena : e.ocjene)
            {
                std::cout << "\tNaziv predmeta: " << ocjena.predmet->naziv << std::endl;
                std::cout << "\tOcjena: " << ocjena.ocjena << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

void edit(std::list<Predmet> &predmeti, std::vector<Student> &studenti)
{
    std::string brojIndeksa;
    std::cout << "Unesite broj indeksa studenta: ";
    std::getline(std::cin, brojIndeksa);
    auto it = studenti.begin();
    while (it != studenti.end())
    {
        if (brojIndeksa == (*it).brojIndeksa)
        {
            break;
        }
        ++it;
    }
    if (it == studenti.end())
    {
        std::cout << "Ne postoji student sa unesenim brojem indeksa!\n"
                  << std::endl;
    }
    else
    {
        short option;
        std::cout << "1. Mijenanje broja indeksa studenta" << std::endl;
        std::cout << "2. Mijenanje imena studenta" << std::endl;
        std::cout << "3. Mijenanje prezime studenta" << std::endl;
        std::cout << "4. Mijenanje grada studenta" << std::endl;
        std::cout << "5. Brisanje svih ocjena" << std::endl;
        std::cout << "6. Dodavanje novih ocjena" << std::endl;
        std::cout << "7. Nazad" << std::endl;
        do
        {

            std::cout << "Unesite broj opcije: ";
            std::cin >> option;
            std::cout << std::endl;
            if (option < 1 || option > 7)
            {
                std::cout << "Uneseni broj nije medju opcijama" << std::endl;
                std::cin.clear();
                std::cin.ignore();
            }
        } while (option < 1 || option > 7);
        std::cin.ignore();
        switch (option)
        {
        case 1:
        {
            std::cout << "Unesite novi broj indeksa: ";
            std::getline(std::cin, it->brojIndeksa);
            break;
        }

        case 2:
        {
            std::cout << "Unesite novo ime: ";
            std::getline(std::cin, it->ime);
            break;
        }
        case 3:
        {
            std::cout << "Unesite novo prezime: ";
            std::getline(std::cin, it->prezime);
            break;
        }
        case 4:
        {
            std::cout << "Unesite novi grad: ";
            std::getline(std::cin, it->grad);
            break;
        }
        case 5:
        {
            it->ocjene.clear();
            break;
        }
        case 6:
        {
            it->ocjene = unesi_ocjene(predmeti, studenti);
            break;
        }
        case 7:
        {
            return;
            break;
        }
        }
    }
}

void menu(short &option)
{
    do
    {
        std::cout << "1. Unos novih predemta" << std::endl;
        std::cout << "2. Unos studenata" << std::endl;
        std::cout << "3. Editovanje studenata" << std::endl;
        std::cout << "4. Ispis svih studenata" << std::endl;
        std::cout << "5. Izlaz" << std::endl;

        std::cout << "Unesite broj opcije: ";
        std::cin >> option;
        std::cout << std::endl;
        if (option < 1 || option > 5)
        {
            std::cout << "Odabrali ste nepostojecu opciju!" << std::endl;
            std::cin.ignore();
            std::cin.clear();
        }
    } while (option < 1 || option > 5);
    std::cin.ignore();
}
