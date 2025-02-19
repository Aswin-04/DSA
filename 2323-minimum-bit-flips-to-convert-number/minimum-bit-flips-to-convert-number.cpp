class Solution {
public:

    string decimalToBinary(int n) {
        string res1 = "";
        if(n == 0) res1+='0';
        while(n >= 1) {
            if(n%2 == 0) res1+='0';
            else res1+='1';
            n/=2;
        }

        string res2 = "";
        for(int i=0; i <= 30-(res1.size()); i++) {
            res2+="0";
        }

        reverse(res1.begin(), res1.end());
        return res2+res1;
    }   

    int minBitFlips(int start, int goal) {
        string sstart = decimalToBinary(start);
        string sgoal = decimalToBinary(goal);

        int ans = 0;
        for(int i=0; i < sstart.size(); i++) {
            if(sstart[i] != sgoal[i]) ans++;
        } 

        return ans;
    }
};