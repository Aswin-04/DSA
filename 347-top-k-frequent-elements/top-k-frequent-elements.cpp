class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }

        vector<pair<int, int>> freq_vec;
        for(const auto &p: freq_map) {
            freq_vec.push_back(p);
        }
        sort(freq_vec.begin(), freq_vec.end(), [](const pair<int, int> mp1, const pair<int, int> mp2) {
            return mp1.second >= mp2.second;
        });

        vector<int> ans;
        int i = 0;
        for (auto p : freq_vec) {
            if (i >= k)
                break;
            ans.push_back(p.first);
            i++;
        }

        return ans;
    }
};