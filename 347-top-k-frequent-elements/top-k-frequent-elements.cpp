class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // SC --> O(N)
        // TC --> O(N)
        unordered_map<int, int> freq;     
        for(int val: nums) freq[val]++;

        int size = nums.size()+1;
        vector<vector<int>> bucket(size);
        for(auto p: freq) {
            bucket[p.second].push_back(p.first);
        }

        int ctr = 0;
        vector<int> res;
        for(int i=size-1; i >= 0; i--) {
            for(int j=0; j < bucket[i].size(); j++, ctr++) {
                if (ctr >= k) break;
                res.push_back(bucket[i][j]);
            }
        }

        return res;

    }
};