class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        helper(0, target, comb, candidates, res);
        return res;
    }

private:
    void helper(int idx, int target, vector<int>& comb, vector<int>& candidates, vector<vector<int>>& res) {

        if(idx >= candidates.size() || target < 0) return;

        if(target == 0) {
            res.push_back(comb);
            return;
        }

        for(int i=idx; i < candidates.size(); i++) {
            comb.push_back(candidates[i]);
            helper(i, target-candidates[i], comb, candidates, res);
            comb.pop_back();
        }
    }
};