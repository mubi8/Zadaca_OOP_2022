#include<functional>
#include<iostream>
#include<list>


std::list<int> partitionn(std::list<int>::const_iterator begin, 
                         std::list<int>::const_iterator end,
                         std::function<bool(int)> predicate) {
    std::list<int> result;
    while(begin != end) {
        if(predicate(*begin)) {
            result.push_front(*begin);
        } else {
            result.push_back(*begin);
        }
        begin++;
    }
    return result;

}


int main(){
    std::list<int> numbers{15, 20, 25, -10, -75, 100, -255, 430, 200};

    std::cout << "Original list:" << std::endl;
    for (int &e : numbers) {
    std::cout << e << " ";
    }
    std::cout << std::endl << std::endl;
    auto result = partitionn(numbers.cbegin(), numbers.cend(),
                                      [](int num) { return !(num % 2); });
    
        for (auto &e : result) {
        std::cout << e << " ";
        }
        std::cout << std::endl;

    std::cout << "Original list:" << std::endl;
    for (int &e : numbers) {
    std::cout << e << " ";
    }
    std::cout << std::endl << std::endl;

    result=partitionn(numbers.cbegin(),numbers.cend(),[](int n){
                                                    return n>0;});

    for (auto &e : result) {
        std::cout << e << " ";
        }
        std::cout << std::endl;

    std::cout << "Original list:" << std::endl;
    for (int &e : numbers) {
    std::cout << e << " ";
    }
    std::cout << std::endl << std::endl;


    return 0;
    
}
