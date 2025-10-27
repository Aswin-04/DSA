class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int &val: nums) freq[val]++;

        int n = nums.size();
        vector<vector<int>> arr(n+1);
        for(pair<const int, int> &pr: freq) {
            arr[pr.second].push_back(pr.first);
        }

        vector<int> res;
        for(int i=0; i <= n; i++) {
            sort(arr[i].rbegin(), arr[i].rend());
            for(int &val: arr[i]) {
                for(int k=0; k < i; k++) res.push_back(val);
            }
        }

        return res;
    }
};