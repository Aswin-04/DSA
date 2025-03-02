class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int i=0;
        int left = 0;
        int right = 0;

        while(i < n) {
            while(i < n && s[i] == ' ') i++;
            if(i == n) break;
            
            while(i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }

            reverse(s.begin()+left, s.begin()+right);
            s[right++] = ' ';
            left = right;
            i++;
        }

        s = s.substr(0, right-1);
        return s;
    }
};