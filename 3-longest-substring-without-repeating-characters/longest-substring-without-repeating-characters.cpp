class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> hash(256, -1);
        int i=0;
        int j=0;
        int res = 0;

        while(i <= j && j < n) {   // O(N)
            if(hash[s[j]] != -1) {  // O(1)
                res = max(res, j-i);
                if(hash[s[j]] >= i) i = hash[s[j]] + 1;
            }

            hash[s[j]] = j;  // O(1)
            j++;
        }

        if(i < j) res = max(res, j-i);
        return res;

        // TC --> O(N)
        // SC --> O(256)
    }
};