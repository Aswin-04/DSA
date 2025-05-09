class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int max_cnt = 0;
        for(int val: nums) st.insert(val);
        for(int val: st) {
            if(st.count(val-1)) continue;
            int cnt = 0;
            int num = val;
            while(st.count(num)) {
                num++;
                cnt++;
            }
            max_cnt = max(max_cnt, cnt);
        }

        return max_cnt;
    }
};