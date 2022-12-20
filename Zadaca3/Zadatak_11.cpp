/*Implementirati klase Radnik i BazaRadnika koja implementira bazu radnika i omogućava:
● Unos pojedinačnog radnika u bazu. Baza ne dozvoljava unos dva radnika istog imena.
Ukoliko se pokuša unijeti isti radnik dva puta, metod generira iznimku tipa domain_error.
● Brisanje radnika određenog imena iz baze. Metod za brisanje kao rezultat vraća uspješnost
operacije.
● Unos i ispis kompletne baze pomoću objekata tipa istream i ostream.
● Računanje prosječne plate i starosti radnika.*/
#include<iostream>
#include<vector>

struct Radnik {
    std::string ime;
    std::string prezime;
    int godineStarosti;
    double plata;
};

class BazaRadnika {
    std::vector<Radnik> baza;
    public:
    void unos(std::istream& unos) {
    Radnik r;
    while(unos>>r.ime>>r.prezime>>r.godineStarosti>>r.plata) {
        try{
        for(auto it=baza.begin();it!=baza.end();it++) {
            if(r.ime==it->ime) {
                throw std::domain_error("Radnik je vec u bazi");
                
            }
        }
        baza.push_back(r);
    } catch(std::domain_error&e) {
        std::cout<<e.what()<<std::endl;
    }
    }
    }
    void ispisi(std::ostream& out) {
        for(auto it=begin(baza);it!=end(baza);it++) {
            out<<it->ime<<" "<<it->prezime<<" "<<it->godineStarosti<<" "<<it->plata<<std::endl;
        }
    }
};

int main() {
    BazaRadnika r;
    r.unos(std::cin);
    r.ispisi(std::cout);
}