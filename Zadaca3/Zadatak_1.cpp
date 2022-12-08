#include<iostream>
#include<list>

std::list<int> parni_neparni(std::list<int>::const_iterator&& i1, std::list<int>::const_iterator&& i2){
    std::list<int> result;
    while (i1!=i2)
    {
        if(*(i1)%2==0){
            result.push_front(*i1);
        }else{
            result.push_back(*i1);
        }
        i1++;
    }
    return result;
}
// advance(InputIterator& it, Distance N)

int main(){

    std::list<int> lista{2,7,9,10,11,15,16,8,30,44,23};
      //auto it=begin(lista);
      //std::advance(it,3);

    std::list<int>result= parni_neparni(begin(lista),lista.end()); // paziti sa advance na reference ne moze rvalue i lvalue advance daje lvalue

    for(auto && e:result){
        std::cout<< e << " ";
    }

}