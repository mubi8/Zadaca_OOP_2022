/*Implementirati generičku funkciju sort(p,k,f) koja kao argumente uzima početak i kraj sekvence
koju treba sortirati [p,k) te binarnu predikat funkciju f(a,b) koja definiše kriterij za sortiranje.
Binarna predikat funkcija vraća tačnu vrijednost ukoliko element a treba u sekvenci biti prije
elementa b, u suprotnom vraća netačno. Ukoliko se funkcija sort pozove bez trećeg argumenta
(pozove se sort(p,k)), elemente sortirati od manjeg ka većem. Funkciju sort definisati u
namespace-u my, u zaglavlju my.hpp.*/
#include<iostream>
#include<functional>
#include<vector>
#include<list>

namespace moj {
    template<typename T,class Lambda>
    void sort(T prvi, T drugi, Lambda f) {
        if(prvi==drugi) {
            return;
        }
        bool  swapped;
        T last_swap=--drugi;
        T it=prvi;
        do {
            swapped=false;
            while(it!=last_swap) {
                if(!f(*it,*(std::next(it)))) {
                    std::swap(*it,*(std::next(it)));
                    swapped=true;
                }
                ++it;

            }
            last_swap=prvi;
            std::advance(last_swap,std::distance(prvi,it)-1);
            it=prvi;
        }while(swapped);

    }

    template<typename T> 
    void sort(T prvi, T drugi) {
        if(prvi==drugi) {
            return;
        }
        bool swapped;
        T last_swap=--drugi;
        T it=prvi;
        do {
            swapped=false;
            while(it!=last_swap) {
                if(*it>*(std::next(it))) {
                    swapped=true;
                    std::swap(*it,*(std::next(it)));
                }
                ++it;
            }
            last_swap=prvi;
            std::advance(last_swap,std::distance(prvi,it)-1);
            it=prvi;

        }while(swapped);
    }

}

int main() {
    std::vector<int> v{2,10,3,5,1,20,24,13,20,43,13,17,7,20};
    //moj::sort(begin(v),end(v),[](int a, int b){return a<b;});
    moj::sort(begin(v),end(v));
    for(auto &&e:v) {
        std::cout<<e<<" ";
    }
}
