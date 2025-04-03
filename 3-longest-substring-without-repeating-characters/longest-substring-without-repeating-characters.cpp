class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char, int> mp;
        int i=0;
        int j=0;
        int res = 0;

        while(i <= j && j < n) {
            if(mp.find(s[j]) != mp.end()) {
                res = max(res, j-i);
                if(i <= mp[s[j]]) i = mp[s[j]] + 1;
            }

            mp[s[j]] = j;
            j++;
        }

        if(i < j) res = max(res, j-i);
        return res;
    }
};