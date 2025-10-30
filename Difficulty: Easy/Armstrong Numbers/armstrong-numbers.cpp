// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int num = n;
        int res = 0;
        int digits = log10(n)+1;
        while(num) {
            res+=pow(num%10, digits);
            num/=10;
        }
        return n == res;
    }
};