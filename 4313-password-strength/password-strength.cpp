class Solution {
public:
    bool lowc(char ch) {
        return ch<='z' && ch>='a';
    }
    bool uppc(char ch) {
        return ch<='Z' && ch>='A';
    }
    bool digi(char ch) {
        return ch<='9' && ch >='0';
    }
    bool spcl(char ch) {
        return ch=='!' || ch=='@' || ch=='#' || ch=='$';
    }
    int passwordStrength(string password) {
        unordered_set<char> check;
        int ans = 0;

        for(char c : password) {
            if(check.count(c)) {
                continue;
            }

            if(lowc(c)) {
                ans += 1;
            }
            else if(uppc(c)) {
                ans += 2;
            }
            else if(digi(c)) {
                ans += 3;
            }
            else if(spcl(c)) {
                ans += 5;
            }
            check.insert(c);
        }
        return ans;
    }
};