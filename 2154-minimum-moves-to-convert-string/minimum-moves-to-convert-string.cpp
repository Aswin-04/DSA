class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size();
        int ctr = 0;
        int i=0;

        while(i+2 < n) {
            if(s[i] == 'O') i++;
            else {
                bool hasX = false;
                if(s[i] == 'X' || s[i+1] == 'X' || s[i+2] == 'X') {
                    hasX = true;
                }
                if(hasX) ctr++;
                i+=3;
            }
        }

        bool hasX = false;
        while(i < n) {
            if(s[i] == 'X') hasX = true;
            i++;
        }

        if(hasX) ctr++;
        return ctr;

    }
};