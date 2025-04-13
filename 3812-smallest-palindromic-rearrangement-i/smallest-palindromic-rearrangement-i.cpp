class Solution {
public:
    string smallestPalindrome(string s) {

        int n = s.size();
        vector<int> freq(26, 0);
        string res(n, '\0');
        for(char ch: s) freq[ch-97]++;

        int j=0;
        int midChar = -1;
        for(int i=0; i < 26; i++) {
            while(freq[i] >= 2) {
                res[j] = 'a' + i;
                res[n-j-1] = 'a' + i;
                freq[i]-=2;
                j++;
            }

            if(freq[i] == 1) midChar = i; 
        }

        if(midChar != -1) {
            res[(n-1)/2] = 'a' + midChar;
        }

        return res;
    }
};