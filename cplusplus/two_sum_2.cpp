#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = size(numbers) - 1;
        int result = 0;
        for (int i = 0; i < size(numbers); i++) {
            result = numbers[left] + numbers[right];
            if (target == result){
                return {left+1, right+1};
            }
            else if (target > result){
                left += 1;
            }
            else{
                right -= 1;
            }
        }
        return {};
    }
};