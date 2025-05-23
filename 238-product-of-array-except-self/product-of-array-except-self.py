class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        pref = []
        suff = []

        prod = 1
        for i in range(len(nums)):
            pref.append(prod)
            prod *= nums[i]


        prod = 1
        for i in range(len(nums)-1,-1,-1):
            pref[i] *= prod
            prod *= nums[i]
        
        return pref
        