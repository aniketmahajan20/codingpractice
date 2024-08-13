#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <cmath>
#include <unordered_map>

using namespace std;
class Solution {
private:
    unordered_map<int, int> dict;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if (dict.find(complement) != dict.end()){
                return {i, dict[complement]};
            }
            dict[nums[i]] = i;
        }
        return {};
    }
};