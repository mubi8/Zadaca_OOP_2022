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

int main()
{

    std::list<double> lista1{2.0, 3.65, 8.23, -5.56, 3.889, 10.0, -123.4};
    std::list<char> lista2{'a', 'b', 'c', 'f', 'G', 'H', 'J', 'L'};
    std::cout << "Orginalna lista doublova lista1: ";
    for (auto &&e : lista1)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    auto nova_lista = filter(lista1, [](int num)
                             { return num %2==0; });

    std::cout << "Modifikovana lista1: ";
    for (auto &&e : nova_lista)
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