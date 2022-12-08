#include <iostream>
#include <list>
#include <functional>

std::list<int> map(std::list<int> lista, std::function<int(int)> predicate)
{

    std::list<int> nova_lista;
    for (auto it = begin(lista); it != end(lista); it++)
    {
        nova_lista.push_back(predicate(*it));
    }
    return nova_lista;
}
int main()
{
    std::list<int> input_list{7, 2, -4, 5, 0, 6, 3};
    auto nova_lista = map(input_list, [](int num)
                          { return num * 2 + 1; });
    std::cout << "Orginalna lista je: " << std::endl;
    for (auto &&e : input_list)
    {
        std::cout << e << " ";
    }
    std::cout<<'\n';
    std::cout << "Modifikovana lista je: " << std::endl;
    for (auto &&e : nova_lista)
    {
        std::cout<<e<<" ";
    }

    return 0;
}
