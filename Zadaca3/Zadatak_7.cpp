#include<iostream>
#include<list>
#include<functional>


int reduce(std::list<int>&lista,std::function<int(int,int)> predicate,int n){
    int suma=0;
    for(auto it=begin(lista);it!=end(lista);it++){

        suma=predicate(*it,suma);

    }
    return suma+n;
}
int main(){
    int broj;
    std::cout<<"Od kojeg broja zelis da ti starta suma: ";
    std::cin>>broj;
    std::list<int> lista{11, 4, 5, 12, 6, 8, 9};
    auto rezultat=reduce(lista,[](int a, int b){return a+b+1;},broj);
    std::cout<<rezultat;
}