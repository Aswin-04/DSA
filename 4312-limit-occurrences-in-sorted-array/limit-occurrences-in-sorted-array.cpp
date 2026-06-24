class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> res;

        for(int c : nums) {
            if(res.size() < k || res[res.size()-k] != c) {
                res.push_back(c);
            }
        }
        return res;
    }
};