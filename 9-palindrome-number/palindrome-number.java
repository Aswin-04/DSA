class Solution {
    private static int reverseNum(int x) {

        int revNum = 0;
        while(x != 0) {
            int lastDigit = x % 10;
            revNum = revNum * 10 + lastDigit;
            x/=10;
        }

        return revNum;
    }

    public boolean isPalindrome(int x) {
        if(x < 0) return false;
        return reverseNum(x) == x;
    }
}