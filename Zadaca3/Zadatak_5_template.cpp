#include <iostream>
#include <functional>
#include<list>

template <typename T>
std::list<T> filter(std::list<T> lista, std::function<bool(int)> predicate)
{

    std::list<T> nova_lista;
    for (auto it = begin(lista); it != end(lista); it++)
    {
        auto uslov = predicate(*it);
        if (uslov == true)
        {
            nova_lista.emplace_back(*it);
        }
    }
    return nova_lista;
}

template<typename T>
T filter(T prvi, std::function<bool(int)> predicate) {
    T novi_vec;
    for(auto it=begin(prvi);it!=end(prvi);it++) {
        auto uslov=predicate(*it);
        if(uslov==true) {
            novi_vec.push_back(*it);
        }
    }
    return novi_vec;
}
int main()
{
    std::vector<int> vec {1,2,3,4,5,6};
    std::list<double> lista1{2.0, 3.65, 8.23, -5.56, 3.889, 10.0, -123.4};
    std::list<char> lista2{'a', 'b', 'c', 'f', 'G', 'H', 'J', 'L'};
    std::cout << "Orginalna lista doublova lista1: ";
    for (auto &&e : vec)
    {
        std::cout << e << " ";
    }
    auto novi_vec=filter(vec,[](int num)
                             { return num %2==0; });
    std::cout << std::endl;
    std::cout<<novi_vec.size();
    auto nova_lista = filter(lista1, [](int num)
                             { return num %2==0; });

    std::cout << "Modifikovani vektor: ";
    for (auto &&e : novi_vec)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << "Orginalna lista charova lista2: ";
    for (auto &&e : lista2)
    {

        std::cout << e << " ";
    }
    std::cout << std::endl;
    auto nova_lista2 = filter(lista2, [](int num)
                              { return num % 2 == 0; });
    std::cout << "Nova modifikovana lista2 je: ";
    for (auto &&e : nova_lista2)
    {
        std::cout <<e<< " ";
    }

    return 0;
}