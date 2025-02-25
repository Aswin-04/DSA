class Solution {
public:
    double myPow(double x, int n) {
        

        long long m = n;
        if(n < 0) m = 0-1LL*n;
        double ans = 1;

        while(m > 0) {
            if(m%2 == 1) {
                ans = ans*x;
                m--;
            }

            else {
                m/=2;
                x*=x;
            }
        }

        if(n < 0) ans = (1.0/ans);
        return ans;
    }
};