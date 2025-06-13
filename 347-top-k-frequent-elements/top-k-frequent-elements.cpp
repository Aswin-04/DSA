class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, vector<int>> freqHash;
        map<int, int> freqArr;
        vector<int> ans;

        for(int i=0; i < nums.size(); i++) {
            freqArr[nums[i]]++;
        }

        for(auto pr: freqArr) {
            freqHash[pr.second].push_back(pr.first);
        }

        int i=0;
        for(auto itr = freqHash.rbegin(); itr != freqHash.rend(); itr++) {
            for(int freq: itr->second) {
                if(i >= k) break;
                ans.push_back(freq);
                i++;
            }
        }

        return ans;

    }
};