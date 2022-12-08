#include<iostream>
#include<list>
#include<functional>

std::list<int> filter(std::list<int> druga,std::function<bool(int)> predicate) {
    std::list<int> nova_lista;
    for(auto it=druga.begin();it!=druga.end();it++){
        if(predicate(*it)){
            nova_lista.push_back(*it);
        }

    }

    return nova_lista;

}

int main(){
    std::list<int> lista{1, 9, 8, 4, 11, 0, 2, 6, 15, 3, 10};
    auto nova_lista=filter(lista,[](int num){return num%2==0;});

    std::cout<<"Orginalna lista: "<<std::endl;
    for(auto&& e:lista){
        std::cout<<e<<" ";
    }

    std::cout<<std::endl;
    std::cout<<"Nova lista: "<<std::endl;
    for(auto&& e:nova_lista){
        std::cout<<e<<" ";
    }
    std::cout<<std::endl;

}