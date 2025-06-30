class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size();
        int ctr = 0;
        int i=0;

        while(i < n) {
            if(s[i] == 'O') i++;
            else {
                ctr++;
                i+=3;
            }
        }
        
        return ctr;

    }
};