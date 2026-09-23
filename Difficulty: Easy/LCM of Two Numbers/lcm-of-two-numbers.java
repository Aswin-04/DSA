class Solution {
    public int lcm(int a, int b) {
        // code here
        return (a*b)/gcd(a, b);
    }
    
    private int gcd(int a, int b) {
        if(a == 0) return b;
        return gcd(b%a, a);
    }
}