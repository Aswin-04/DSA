class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // TC --> O(N)
        // SC --> O(1)
        
        int n = nums.size();
        vector<int> answer(n);

        int product = 1;
        for(int i=0; i < n; i++) {
            answer[i] = product;
            product*=nums[i];
        }

        product = 1;
        for(int i=n-1; i >= 0; i--) {
            answer[i]*=product;
            product*=nums[i];
        }

        return answer;
    }
};