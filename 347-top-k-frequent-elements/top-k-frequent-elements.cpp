class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }

        int n = nums.size();
        vector<vector<int>> bucket(n+1);
        for(const auto &p: freq_map) {
            bucket[p.second].push_back(p.first);
        }

        vector<int> ans;
        for(int i=n; i >= 1; i--) {
            for(int j=0; j < bucket[i].size(); j++) {
                if(ans.size() == k) return ans;
                ans.push_back(bucket[i][j]);
            }
        }

        return ans;
    }
};