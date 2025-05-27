class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // TC --> O(n) && SC --> O(n)
        unordered_set<int> st;
        int max_len = 0;
        for(int val: nums) st.insert(val);
        for(int val: st) {
            if(st.count(val-1)) continue;
            int ctr = 0;
            int temp = val;
            while(st.count(temp)) {
                temp++;
                ctr++;
            }

            max_len = max(max_len, ctr);
        }

        return max_len;
    }
};