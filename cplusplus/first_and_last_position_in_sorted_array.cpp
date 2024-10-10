#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return {-1,-1};
        }
        int start_index = 0;
        int end_index = nums.size()-1;
        int hi = end_index;
        int lo = 0;
        int mid = 0;
        // Finding the beginning index
        while(lo<=hi){
            mid = (lo + hi)/2;
            if (nums[mid] == target){
                if (mid == start_index || nums[mid-1] != target){
                    start_index = mid;
                    break;
                }
                hi = mid - 1;
            }
            else if (nums[mid] < target){
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        hi = end_index;
        lo = start_index;
        while(lo<=hi){
            mid = (lo + hi)/2;
            if (nums[mid] == target){
                if (mid == end_index || nums[mid+1] != target){
                    end_index = mid;
                    break;
                }
                lo = mid + 1;
            }
            else if (nums[mid] < target){
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        if (nums[start_index] == target){
            return {start_index, end_index};
        }
        return {-1,-1};
    }
};