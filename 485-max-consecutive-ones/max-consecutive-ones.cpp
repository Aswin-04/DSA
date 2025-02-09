class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_cnt = 0;
        int cnt = 0;

        for(int i: nums) {
            if(i == 0) {
                max_cnt = max(max_cnt, cnt);
                cnt=0;
            }
            else cnt++;
        }

        return max(max_cnt, cnt);
    }
};