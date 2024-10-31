class QuickSort():
    def quick_sort(self, nums: list):
        self.q_sort(nums, 0, len(nums)-1)
        return nums
    
    def q_sort(self, nums, lo, hi):
        """Recursively call itself. 
        Identifies a pivot, then runs again for the next range.

        Args:
            nums (list): list to sort
            lo (int): starting point for the array to be sorted
            hi (int): end point for the sub-array to be sorted
        """
        if lo<hi:
            pivot = self.partition(nums, lo, hi)
            self.q_sort(nums, lo, pivot - 1)
            self.q_sort(nums, pivot +1, hi)

    def partition(self, nums, lo, hi):
        """Uses the two pointer technique to swap numbers.
        after the loop is finished, pivot is at hi.
        i is the index where pivot should originally be.

        Args:
            nums (list): list to sort
            lo (int): starting point for the array to be sorted
            hi (int): end point for the sub-array to be sorted

        Returns:
            _type_: _description_
        """
        pivot = nums[hi]
        i = lo
        for j in range(lo,hi):
            if (nums[j] < pivot):
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
        nums[i], nums[hi] = nums[hi], nums[i]
        return i

if __name__ == "__main__":
    sorter = QuickSort()
    nums = ["aniket", "mahajan", "is", "being", "sorted"]
    print(sorter.quick_sort(nums))