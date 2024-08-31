#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

// Initial Solution for Three sum problem. NO SORT. 
// Fails with TLE for one of the cases

class SolutionNoSort {
private:
    set<vector<int>> result;
    unordered_map<int, int> unique_nums;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        for (int i = 0; i < size(nums); i++){
            unique_nums[nums[i]] = i;
        }
        for (int i = 0; i < size(nums); i++) {
             for  (int j = i +1; j < size(nums); j++) {
                if (unique_nums.find(-nums[i] - nums[j]) != unique_nums.end()) {
                    if (i != unique_nums[-nums[i] - nums[j]] and j != unique_nums[-nums[i] - nums[j]]){
                        vector<int> vec = {nums[i], nums[j], (-nums[i] - nums[j])};
                        sort(vec.begin(), vec.end());
                        result.emplace(vec);
                    }
                }
             }
        }
        return vector<vector<int>>(begin(result), end(result));
    }
};

// Implementing the two pointer solution which takes 
// elements from the TWO SUM 2 problem
class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the array
        sort(nums.begin(), nums.end());
        // For loop iterating over the nums array fixing the first element
        int left, right = 0;
        for (int i = 0; i < size(nums); i++){
            if (nums[i] > 0){
                break;
            }
            // if the current element is the same as previous, continue the loop
            if (i != 0){
                if (nums[i] == nums[i-1]) {
                    continue;
                }
            }
            // Initialise the two pointers to use in the for loop 
            left = i + 1;
            right = size(nums)-1;
            // For loop iterating from i+1 to the end
            for (int j = i +1; j < size(nums); j++){
                if (left >= right) {
                    break;
                }
                // if solution is found, emplace to the result and continue searching
                if (nums[i] == -nums[left] - nums[right]){
                    result.push_back({nums[i], nums[left], nums[right]});
                    left+=1;
                    right-=1;
                    while(nums[left] == nums[left-1] && left < right){
                        left+=1;
                    }
                }
                // if sum is less than the target, move left pointer by 1
                else if (-nums[i] > nums[left] + nums[right]) {
                    left +=1;
                }
                // if sum is higher than the target, move the right pointer by 1
                else{
                    right -=1;
                }
            }
        }
        return result;
    }
};