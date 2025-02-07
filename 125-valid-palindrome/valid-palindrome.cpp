class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for(char ch: s) {
            if(isalnum(ch)) t+=ch;
        }

        int n = t.size();
        for(int i=0; i < n/2; i++) {
            if( tolower(t[i]) != tolower(t[n-1-i]) ) return false;
        }

        return true;
    }
};