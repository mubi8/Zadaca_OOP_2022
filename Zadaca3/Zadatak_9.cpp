#include <algorithm>
#include <iostream>
#include <string>

template <typename T> 
bool jednako(T begin1, T end1, T begin2) {
  while (begin1 != end1) {
    if (*begin1 != *begin2) {
      return false;
    }
    ++begin1;
    ++begin2;
  }
  return true;
}

int main() {
  std::string word;
  while (std::cin >> word) {
    std::string reverse = std::string(word.rbegin(), word.rend());
    if (jednako(word.cbegin(), word.cend(), reverse.cbegin())) {
      std::cout << word << ": Palindrom" << std::endl;
    }
  }
  return 0;
}