class Solution {
    public String frequencySort(String s) {

        int[] freq = new int[128];
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i)]++;
        }

        HashMap<Integer, StringBuilder> bucket = new HashMap<>();
        for (int i = 0; i < 128; i++) {
            if (freq[i] == 0)
                continue;
            bucket.putIfAbsent(freq[i], new StringBuilder());
            bucket.get(freq[i]).append((char) i);
        }

        StringBuilder res = new StringBuilder();
        for (int i = s.length(); i > 0; i--) {
            if (bucket.containsKey(i)) {
                StringBuilder str = bucket.get(i);
                for (int j = 0; j < str.length(); j++) {
                    res.append(String.valueOf(str.charAt(j)).repeat(i));
                }
            }
        }

        return res.toString();
    }
}