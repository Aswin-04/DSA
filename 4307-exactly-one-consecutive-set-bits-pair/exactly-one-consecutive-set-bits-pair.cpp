class Solution {
public:
    string toBinary(int n) {
        if (n == 0)
            return "0";

        string res;

        while (n > 0) {
            res.push_back((n % 2) + '0');
            n /= 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
    bool consecutiveSetBits(int n) {
        string d = toBinary(n);
        int adjpr = 0;

        for (int i = 0; i + 1 < d.size(); i++) {
            if (d[i] == '1' && d[i + 1] == '1') {
                adjpr++; 
            }
        }
        return adjpr == 1;
    }
};