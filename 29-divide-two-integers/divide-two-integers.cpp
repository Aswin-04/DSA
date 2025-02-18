class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        int is_neg = 0;
        if((dividend < 0 && divisor >= 0) || (dividend >= 0 && divisor < 0)) is_neg = 1;
        
        long n = labs(dividend);
        long d = labs(divisor);
        long ans = 0;

        while(n >= d) {
            int i=0;
            while(n >= d<<(i+1)) {
                i++;
            }
            ans+=(1 << i);
            n-= (d << i);
        }

        if(ans == (1<<31) && !is_neg) return INT_MAX;
        else if(ans == (1<<31) && is_neg) return INT_MIN;

        return (is_neg) ? 0-ans : ans;
    }
};