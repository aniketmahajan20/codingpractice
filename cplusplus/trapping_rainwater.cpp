#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int total_water = 0;
    int left_max, right_max, left, right;
public:
    int trap(vector<int>& height) {
        // Initialize the two pointers
        left = 0;
        right = size(height) - 1;
        left_max = height[left];
        right_max = height[right];
        // while left pointer < right pointer
        while (left < right){
            // if height[left] < height[right]
            if (height[left] < height[right]){
                // if left_max < height[left]
                if (left_max < height[left]) {
                    // change left_max to height[left]
                    left_max = height[left];
                }
                // else 
                else{
                    // add left_max - height[left] to ans
                    total_water += left_max - height[left];
                }
                // move left pointer to right by one
                left +=1;
            }
                
            // else
            else{
                // if right_max < height[right]
                if (right_max < height[right]) {
                    // change right_max to height[right]
                    right_max = height[right];
                }
                // else 
                else{
                    // add right_max - height[right] to ans
                    total_water += right_max - height[right];
                }
                // move right pointer to left by one
                right -=1;
            }
                
        }
        return total_water;
    }
};