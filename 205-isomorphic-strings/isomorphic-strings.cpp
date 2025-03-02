class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int freq1[256] = {0};
        int freq2[256] = {0};
        int n = s.size();

        for(int i=0; i< n; i++) {
            if(freq1[s[i]] != freq2[t[i]]) return false;
            freq1[s[i]] = i+1;
            freq2[t[i]] = i+1;
        }

        return true;
    }
};