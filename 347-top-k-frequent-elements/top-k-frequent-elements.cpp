class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }

        vector<pair<int, int>> freq_vec;
        for (const auto& p : freq_map) {
            freq_vec.push_back({p.second, p.first});
        }
        sort(freq_vec.rbegin(), freq_vec.rend());

        vector<int> ans;
        for(int i=0; i < k; i++) {
            ans.push_back(freq_vec[i].second);
        }

        return ans;
    }
};