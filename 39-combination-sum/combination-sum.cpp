class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> comb;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        makeCombination(0, target, comb, candidates, res);
        return res;
    }

private:
    void makeCombination(int idx, int target, vector<int>& comb, vector<int>& candidates, vector<vector<int>>& res) {

        if(target == 0) {
            res.push_back(comb);
            return;
        }

        for(int i=idx; i < candidates.size(); i++) {
            if(candidates[i] > target) {
                for(auto it: comb) cout << it << " ";
                cout << endl;
                return;
            }
            comb.push_back(candidates[i]);
            makeCombination(i, target-candidates[i], comb, candidates, res);
            comb.pop_back();
        }
    }
};