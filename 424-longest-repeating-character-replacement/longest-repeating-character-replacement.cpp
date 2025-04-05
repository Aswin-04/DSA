class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int n = s.size();
        vector<int> freq(26, 0);
        int maxFreq = 0;
        int maxLen = 0;

        while(r < n) {
            freq[s[r]-'A']++;
            maxFreq = max(maxFreq, freq[s[r]-'A']);

            if(r-l-maxFreq+1 > k) {
                freq[s[l]-'A']--;
                l++;
            }

            if(r-l-maxFreq+1 <= k) maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};