class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> subs;
        vector<vector<int>> res;
        makeSubsets(0, subs, nums, res);
        return res;
    }

private:
    void makeSubsets(int idx, vector<int>& subs, vector<int>& nums, vector<vector<int>>& res) {
        
        for(int i=idx; i < nums.size(); i++) {
            if(i != idx && nums[i-1] == nums[i]) continue;
            subs.push_back(nums[i]);
            makeSubsets(i+1, subs, nums, res);
            subs.pop_back();
        }

        res.push_back(subs);
    }
};