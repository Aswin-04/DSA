class Solution {
    public String longestCommonPrefix(String[] strs) {

        StringBuilder sb = new StringBuilder();
        int i = 0;

        while (true) {
            boolean flag = false;
            if (i >= strs[0].length())
                break;
            for (String str : strs) {
                if (i >= str.length()) {
                    flag = true;
                    break;
                }
                if (strs[0].charAt(i) != str.charAt(i)) {
                    flag = true;
                    break;
                }

            }

            if (flag)
                break;
            sb.append(strs[0].charAt(i));
            i++;
        }

        return sb.toString();
    }
}