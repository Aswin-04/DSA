class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int i=0;
        int n = s.size();

        string ans = "";
        string word = "";

        while(i < n && s[i] == ' ') {
            i++;
        } 

        while(i < n) {
            while(i < n && s[i] != ' ') {
                word+=s[i];
                i++;
            }


            if(i == n) break;
            if(word.empty()) {
                i++;
                continue;
            }

            reverse(word.begin(), word.end());
            ans+=' ';
            ans+=word;
            word = "";
            i++;
        }

        if(!word.empty()) {
            reverse(word.begin(), word.end());
            ans+=' ';
            ans+=word;
        }

        return ans.substr(1, ans.size());
    }
};