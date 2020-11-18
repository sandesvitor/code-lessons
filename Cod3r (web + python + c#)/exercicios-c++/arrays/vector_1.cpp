#include <iostream>
#include <vector>


int main() {
    std::vector<int> nums = {1, 2, 3};
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(8);

    nums[0] = 0;

    for(int n : nums)
        std::cout << n << std::endl;

    for(auto i = nums.begin(); i != nums.end(); i++){
        *i += 100;
        std::cout << *i << std::endl;
    }
    
    for(auto i = nums.cbegin(); i != nums.cend(); i++){
        // *i += 100;
        std::cout << *i << std::endl;
    }
    
    for(auto i = nums.rbegin(); i != nums.rend(); i++){
        *i += 100;
        std::cout << *i << std::endl;
    }
    
    for(auto i = nums.crbegin(); i != nums.crend(); i++){
        // *i += 100;
        std::cout << *i << std::endl;
    }
    return 0;
}