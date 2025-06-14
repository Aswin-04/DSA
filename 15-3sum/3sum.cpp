class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> answer;

        for(int i=0; i < n; i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;

            int l=i+1;
            int r=n-1;

            while(l < r) {
                int sum = nums[i]+nums[l]+nums[r];
                if(sum > 0) r--;
                else if(sum < 0) l++;
                else {
                    answer.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(l < n && nums[l-1] == nums[l]) l++;            
                }
            }
        } 

        return answer;
    }
};