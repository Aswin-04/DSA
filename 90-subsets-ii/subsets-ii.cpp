class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subs;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(0, subs, nums, res);
        return res;
    }
private:
    void backtrack(int idx, vector<int>& subs, vector<int>& nums, vector<vector<int>>& res) {
        res.push_back(subs);
        if(idx >= nums.size()) return;

        for(int i=idx; i < nums.size(); i++) {
            if(i > idx && nums[i] == nums[i-1]) continue;

            subs.push_back(nums[i]);
            backtrack(i+1, subs, nums, res);
            subs.pop_back();
        }
    }
};