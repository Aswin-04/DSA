class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> res;
        makeCombination(0, target, comb, candidates, res);
        return res;
    }

private:
    void makeCombination(int idx, int target, vector<int>& comb, vector<int>& candidates, vector<vector<int>>& res) {

        if(idx == candidates.size() || target < 0) return;

        if(target == 0) {
            res.push_back(comb);
            return;
        }

        comb.push_back(candidates[idx]);
        makeCombination(idx, target-candidates[idx], comb, candidates, res);
        comb.pop_back();   
        makeCombination(idx+1, target, comb, candidates, res);  
    }
};