// User function Template for Java
class Solution {
    private static int countDigits(int n) {
        return (int) Math.log10(n) + 1;
    }
    static boolean armstrongNumber(int n) {
        // code here
        int res = 0;
        int temp = n;
        int exp = countDigits(n);
        while(temp != 0) {
            int base = temp % 10;
            res+= Math.pow(base, exp);
            temp/=10;
        }
        
        return res == n;
    }
}