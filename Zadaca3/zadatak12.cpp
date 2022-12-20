#include<iostream>
#include<vector>
#include<stdexcept>


struct vektor{
std::vector<int> vec;
void proba(std::istream& in) {
    int broj;
    while(in>>broj)
    try{
        if(broj==5) {
            throw std::out_of_range{"prevara"};
        }
        vec.push_back(broj);
    }
    catch(std::out_of_range& e) {
        std::cout<<e.what();
    }
}
};
int main() {
    vektor v;
    v.proba(std::cin);
    for(auto& e:v.vec) {
        std::cout<<e<<std::endl;
    } 
return 0;
}