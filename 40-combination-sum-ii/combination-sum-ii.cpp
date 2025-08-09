class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        helper(0, target, candidates, comb, res);
        return res;
    }

private:
    void helper(int idx, int target, vector<int>& candidates, vector<int>& comb, vector<vector<int>>& res) {
        
        if(target == 0) {
            res.push_back(comb);
            return;
        }

        for(int i=idx; i < candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) return;
            comb.push_back(candidates[i]);
            helper(i+1, target-candidates[i], candidates, comb, res);
            comb.pop_back();
        }
    }
};