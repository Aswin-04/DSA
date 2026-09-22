class Solution {
    public int reverse(int x) {
        int res = 0;
        int num = x;

        while(num != 0) {
            int lastDigit = num%10;
            if(res < Integer.MIN_VALUE/10 || res > Integer.MAX_VALUE/10) {
                return 0;
            }
            res = res * 10 + lastDigit;
            num/=10;
        } 

        return res;
    }
}