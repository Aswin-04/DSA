class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int p1=0;
        int p2=0;

        for(int i=0; i < n; i++) {
            if(i%2 == 0) {
                while(p1 < n && nums[p1] < 0) p1++;
                if(p1 < n) ans[i] = nums[p1];
                p1++;
            }

            else {
                while(p2 < n && nums[p2] >= 0) p2++;
                if(p2 < n) ans[i] = nums[p2];
                p2++;
            }
        }

        return ans;
    }
};