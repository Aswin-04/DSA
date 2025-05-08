class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int val: nums) freq[val]++;

        map<int, vector<int>, greater<int>> freq_arr;
        for(auto p: freq) {
            freq_arr[p.second].push_back(p.first);
        }
        
        vector<int> res;
        int i=0;
        for(auto p: freq_arr) {
            for(int val: p.second) {
                if(i >= k) break;
                res.push_back(val);
                i++;
            }
        }

        return res;

    }
};