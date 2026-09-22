class Solution {
    public boolean isPalindrome(int x) {
        
        if(x < 0) return false;
        return x == reverseNumber(x);
    }

    private int reverseNumber(int num) {
        int res = 0;

        while(num != 0) {
            res = (res*10) + (num%10);
            num/=10;
        }

        return res;
    }
}