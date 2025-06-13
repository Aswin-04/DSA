class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // TC --> O(N)
        // SC --> O(N)

        int n = nums.size();
        unordered_map<int, int> freq_hash;
        vector<vector<int>> freq_arr(n+1);
        vector<int> answer;

        for(int i=0; i < nums.size(); i++) {
            freq_hash[nums[i]]++;
        }

        for(auto it = freq_hash.begin(); it != freq_hash.end(); it++) {
            freq_arr[it->second].push_back(it->first);
        }

        int ctr=1;
        for(int i=n; i >= 0; i--) {
            for(int freq: freq_arr[i]) {
                if(ctr > k) break;
                answer.push_back(freq);
                ctr++;
            }
        }

        return answer;
    }
};