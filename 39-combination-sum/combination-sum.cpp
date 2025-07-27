class Solution {
void helper(int idx, int sum, int target, vector<int>& combs, vector<int>& arr, vector<vector<int>>& res) {
    if(idx >= arr.size() || sum > target) return;
    if(sum == target) {
        res.push_back(combs);
        return;
    } 

    combs.push_back(arr[idx]);
    sum+=arr[idx];
    helper(idx, sum, target, combs, arr, res);
    combs.pop_back();
    sum-=arr[idx];
    helper(idx+1, sum, target, combs, arr, res);
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combs;
        helper(0, 0, target, combs, candidates, res);
        return res;
    }
};