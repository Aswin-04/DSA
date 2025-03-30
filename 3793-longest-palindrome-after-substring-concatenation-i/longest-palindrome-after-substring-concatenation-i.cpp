class Solution {
public:

    bool isPalindrome(string s) {
        int n = s.size();
        for(int i=0; i < n/2; i++) {
            if(s[i] != s[n-i-1]) return false;
        }
        return true;
    }
    int longestPalindrome(string s, string t) {
        int n = s.size();
        int m = t.size();
        int ans = 0;

        for(int i=0; i < n; i++) {
            for(int j=i; j <= n; j++) {
                for(int k=0; k < m; k++) {
                    for(int l=k; l <= m; l++) {
                        if(isPalindrome(s.substr(i, j-i) + t.substr(k, l-k))) {
                            ans = max(ans, j+l-i-k);
                        }
                    }
                }
            }
        }

        return ans;
    }
};