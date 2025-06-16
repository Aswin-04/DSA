class Solution {
public:
    int characterReplacement(string s, int k) {
        // TC --> O(N)
        // SC --> O(26)
        int l=0;
        int r=0;
        int n = s.size();
        vector<int> charFreq(26, 0);
        int maxLen = 0;

        while(r < n) {
            charFreq[s[r]-'A']++;

            int maxFreq = 0;
            for(int i=0; i < charFreq.size(); i++) {
                maxFreq = max(maxFreq, charFreq[i]);
            }

            while(l < r && ((r-l+1) - maxFreq) > k) {
                charFreq[s[l]-'A']--;
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;

    }
};