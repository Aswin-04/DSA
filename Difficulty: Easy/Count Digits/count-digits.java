class Solution {
    public int countDigits(int n) {
        // code here
        return ((int) Math.log10(n)) + 1;
    }
}
