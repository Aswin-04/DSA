class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // TC --> O(N) 
        // SC --> O(N)
        // where N is the total no of unique elements in nums

        unordered_set<int> hash_set;
        for(int val: nums) {
            hash_set.insert(val);
        }

        int max_len = 0;
        for(int val: hash_set) {
            if(hash_set.count(val-1)) continue;
            int len = 0;
            int crnt_val = val;
            while(hash_set.count(crnt_val)) {
                crnt_val++;
                len++;
            }
            max_len = max(max_len, len);
        }

        return max_len;
    }
};