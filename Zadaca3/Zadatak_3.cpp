#include <iostream>
#include <list>
#include <functional>
#include <stdexcept>

std::list<int> pratition(std::list<int>::const_iterator begin,
                         std::list<int>::const_iterator end,
                         std::function<bool(int)> predicate)
{
    std::list<int> result;
    try
    {
        for (auto it = begin; it != end; it++)
        {
            if (predicate(*it))

            {

                result.emplace_front(*it);
            }

            else

            {

                result.emplace_back(*it);
            }
        }
    }
    catch (const int &e)
    {
        result.assign(begin, end);
    }
    return result;
}
int main()
{

    std::list<int> numbers{15, 20, 25, -10, -75, 100, -255, 430, 200};
    auto result = pratition(begin(numbers), end(numbers), [](int num)
      { if (num > 400) 
        throw 5;
        return num > 0; });

    for (auto e : result)
    {
        std::cout << e << " ";
    }
}