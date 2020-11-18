#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums;
    nums.assign(10, 1);
    
    nums[0] = 7;
    nums[0] = 7;
    nums[9] = 7;

    nums.erase(nums.begin() + 4);

    for(auto n : nums)
        std::cout << n << " ";

    std::cout << nums.size() << std::endl; 
    nums.clear();
    
    std::cout << nums.size() << std::endl;

    return 0;
}