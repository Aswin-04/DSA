class Solution {
public:

    void helper(int idx, int n, vector<int>& subsequence, vector<vector<int>>& res, vector<int>& arr) {
        
        if(idx >= n) {
            res.push_back(subsequence);
            return;
        }

        subsequence.push_back(arr[idx]);
        helper(idx+1, n, subsequence, res, arr);
        subsequence.pop_back();
        helper(idx+1, n, subsequence, res, arr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subsequence;
        int idx = 0;
        int n = nums.size();
        helper(idx, n, subsequence, res, nums);
        return res;
    }
};