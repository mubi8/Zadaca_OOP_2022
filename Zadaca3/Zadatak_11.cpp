/*Implementirati klase Radnik i BazaRadnika koja implementira bazu radnika i omogućava:
● Unos pojedinačnog radnika u bazu. Baza ne dozvoljava unos dva radnika istog imena.
Ukoliko se pokuša unijeti isti radnik dva puta, metod generira iznimku tipa domain_error.
● Brisanje radnika određenog imena iz baze. Metod za brisanje kao rezultat vraća uspješnost
operacije.
● Unos i ispis kompletne baze pomoću objekata tipa istream i ostream.
● Računanje prosječne plate i starosti radnika.*/
#include <iostream>
#include <vector>

struct Radnik
{
    std::string ime;
    std::string prezime;
    int godineStarosti;
    double plata;
};

class BazaRadnika
{
    std::vector<Radnik> baza;

public:
    void unos(std::istream &unos)
    {
        Radnik r;
        while (unos >> r.ime >> r.prezime >> r.godineStarosti >> r.plata)
        {
            try
            {
                for (auto it = baza.begin(); it != baza.end(); it++)
                {
                    if (r.ime == it->ime)
                    {
                        throw std::domain_error("Radnik je vec u bazi");
                    }
                }
                baza.push_back(r);
            }
            catch (std::domain_error &e)
            {
                std::cout << e.what() << std::endl;
            }
        }
    }
    void ispisi(std::ostream &out)
    {
        for (auto it = begin(baza); it != end(baza); it++)
        {
            out << it->ime << " " << it->prezime << " " << it->godineStarosti << " " << it->plata << std::endl;
        }
    }
    bool izbrisi_radnika(const std::string &ime)
    {
        for (auto it = baza.begin(); it != baza.end(); it++)
        {
            if (it->ime == ime)
            {
                baza.erase(it);
                return true;
            }
        }
        return false;
    }
    double prosjek_godina()
    {
        double godine = 0;
        for (auto it = baza.begin(); it != end(baza); it++)
        {
            godine += it->godineStarosti;
        }
        return godine / baza.size();
    }
    double prosjek_plata()
    {
        double prosjek_plata = 0;
        for (auto it = begin(baza); it != end(baza); it++)
        {
            prosjek_plata += it->plata;
        }
        return prosjek_plata/baza.size();
    }
};

int main()
{
    BazaRadnika b1;
    b1.unos(std::cin);
    if (b1.izbrisi_radnika("Alen"))
    {
        std::cout << "Alen izbrisan" << std::endl;
    }
    else
    {
        std::cout << "Brisanje nije moguce !" << std::endl;
    }
    std::cout << "U bazi su : " << std::endl;
    b1.ispisi(std::cout);
    std::cout << "Prosjek plata je : " << b1.prosjek_plata() << std::endl;
    std::cout << "Prosjek godina je : " << b1.prosjek_godina() << std::endl;
    return 0;
}