#include <vector>

using namespace std;

class Solution {
private:
    int max_area  = 0;
    int right, left;
public:
    int maxArea(vector<int>& height) {
        left = 0;
        right = size(height) - 1;
        int area = 0;
        for (int i = 0; i< size(height); i++){
            area = min(height[left], height[right]) * (right - left);
            if (area > max_area) {
                max_area = area;
            }
            if (height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_area;
    }
};