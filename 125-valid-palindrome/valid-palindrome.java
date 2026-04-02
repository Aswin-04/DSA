class Solution {

    private boolean checkPalindrome(StringBuilder s, int i, int n) {
        if(i >= n/2) return true;
        if(s.charAt(i) != s.charAt(n-i-1)) return false;
        return checkPalindrome(s, i+1, n);
    }
    public boolean isPalindrome(String s) {
        StringBuilder sb = new StringBuilder();
        for(int i=0; i < s.length(); i++) {
            if(Character.isLetterOrDigit(s.charAt(i))) {
                sb.append(Character.toLowerCase(s.charAt(i)));
            }
        }
        return checkPalindrome(sb, 0, sb.length());
    }
}