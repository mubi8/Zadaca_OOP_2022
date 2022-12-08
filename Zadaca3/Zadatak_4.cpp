#include<iostream>
#include<vector>
#include<functional>

typedef std::vector<std::function<bool(int)>> Funkcije;

void default_if_not_all(std::vector<int> &v,Funkcije f, int def=-1){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<f.size();j++){

            auto unos=f.at(j)(v.at(i));
            if(unos==false){
                v.at(i)=def;
            }

        }
    }
}

int main() {
    std::vector<int> vec_brojeva{2,10,-5,25,2000,-5421,403,2020,-3,-199,400};
    Funkcije f{[](int num){return num>0;},[](int num) { return !(num % 10);},[](int num) { return std::abs(num) > 2; }};
   default_if_not_all(vec_brojeva,f);
//    std::cout<<f.size()<<std::endl;
    for (auto &&i : vec_brojeva){
        std::cout<<i<< " ";
    }
    
    return 0;
}