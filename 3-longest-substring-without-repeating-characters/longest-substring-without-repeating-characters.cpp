class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0;
        int j=0;
        vector<int> freq(256, 0);
        int res = 0;
        
        while(i <= j && j < n) {
            freq[s[j]]++;

            while(i < j && freq[s[j]] > 1) {
                freq[s[i]]--;
                i++;
            }

            res = max(res, j-i+1);
            j++;
        }

        return res;
    }
};