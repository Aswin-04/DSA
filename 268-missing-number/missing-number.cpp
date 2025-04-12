class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1 = 0;
        int xor2 = 0;

        for(int i=1; i <= nums.size(); i++) xor1^=i;
        for(int val: nums) xor2^=val;

        return xor1^xor2;
    }
};