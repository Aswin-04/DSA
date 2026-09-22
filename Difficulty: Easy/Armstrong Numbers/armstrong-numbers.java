class Solution {
    static boolean armstrongNumber(int n) {
        // code here
        int num = n;
        int res = 0;
        
        while(num != 0) {
            int ld = num%10;
            res = res + (ld*ld*ld);
            num/=10;
        }
        
        return n == res;
    }
}