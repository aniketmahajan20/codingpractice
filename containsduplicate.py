# A python script to check if an array contains duplicate elements

class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        hashset = set()
        len = 0
        for num in nums:
            hashset.add(num)
            if hashset.__len__ != len + 1:
                return True
            len +=1
        return False

if __name__ == "__main__":
    nums = [1,2,3,4]  
    obj = Solution()
    obj.containsDuplicate(nums)