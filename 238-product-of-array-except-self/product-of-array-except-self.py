class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        pref = [1]
        suff = [1]

        prod = nums[0]

        for i in range(1,len(nums)):
            pref.append(prod)
            prod *= nums[i]

        prod = nums[-1]
        for i in range(len(nums)-2,-1,-1):
            suff.append(prod)
            prod *= nums[i]


        for i in range(len(nums)):
            nums[i]=pref[i]*suff[len(nums)-i-1]
        print(pref)
        print(suff)
        return nums
        