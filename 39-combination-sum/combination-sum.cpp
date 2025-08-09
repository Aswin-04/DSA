class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> res;
        helper(0, target, comb, candidates, res);
        return res;
    }

private:
    void helper(int idx, int target, vector<int>& comb, vector<int>& candidates, vector<vector<int>>& res) {

        if(idx >= candidates.size()) return;

        if(target == 0) {
            res.push_back(comb);
            return;
        }

        if(candidates[idx] <= target) {
            comb.push_back(candidates[idx]);
            helper(idx, target-candidates[idx], comb, candidates, res);
            comb.pop_back();
        }

        helper(idx+1, target, comb, candidates, res);
    }
};