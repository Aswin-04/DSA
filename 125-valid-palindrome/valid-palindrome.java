class Solution {
    public boolean isPalindrome(String s) {
        StringBuilder sb = new StringBuilder();
        for(char ch: s.toCharArray()) {
            if(Character.isLetterOrDigit(ch)) {
                sb.append(Character.toLowerCase(ch));
            }
        }

        return checkPalindrome(sb);
    }

    private boolean checkPalindrome(StringBuilder s) {
        int n = s.length();
        for(int i=0; i < n/2; i++) {
            if(s.charAt(i) != s.charAt(n-i-1)) return false;
        }

        return true;
    }
}