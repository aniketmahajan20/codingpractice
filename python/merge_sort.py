from typing import List
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        if len(nums) <= 1:
            return nums
        pivot = int(nums.size()/2)
        left_list = self.sortArray(nums[0:pivot])
        right_list = self.sortArray(nums[pivot:])
        return self.sort_array(left_list, right_list)
    
    def sort_array(left_list, right_list):
        left = 0
        right = 0
        ret = []
        while(left < len(left_list) and right < len(right_list)):
            if left_list[left]<right_list[right]:
                ret.append(left_list[left])
            else:
                ret.append(right_list[right])
        ret.extend(left_list[left:])
        ret.extend(right_list[right:])
        