class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26);
        int res = 0;
        int n = s.size();
        int l=0;
        int max_freq = 0;

        for(int r=0; r < n; r++) {
            freq[s[r]-'A']++;
            max_freq = max(max_freq, freq[s[r]-'A']);

            int rem = r-l+1-max_freq;
            if(rem > k) {
                freq[s[l]-'A']--;
                l++;
            }

            if(r-l+1-max_freq <= k) res = max(res, r-l+1);
        }

        return res;
    }
};