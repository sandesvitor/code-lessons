#include <iostream>
#include <vector>


std::vector<int> map(std::vector<int> v, int(*fn)(int)){
    std::vector<int> newVector;
    for(auto el: v)
        newVector.push_back((*fn)(el));
    
    return newVector;
}

int main() {

    auto square = [](int x) -> int{ return x * x; };
    auto triple = [](int x) -> int{ return 3 * x; };

    std::vector<int> nums = { 2, 3, 4, 5, 23, 56};
    std::vector<int> squares = map(nums, square);
    std::vector<int> triples = map(nums, triple);

    for(auto s : squares) std::cout << s << " ";

    std::cout << std::endl;
        
    for(auto t : triples) std::cout << t << " ";

    std::cout << std::endl;

    return 0;
}