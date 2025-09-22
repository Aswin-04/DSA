#include<cstdlib>
class Solution {
public:
    int scoreOfString(string s) {
        int absdiff;
        int sum=0;
        for(int i=0; i<s.size()-1; i++) {
            absdiff = (int)s[i]-(int)s[i+1];
            sum = sum + abs(absdiff);
        }
        return sum;
    }
};