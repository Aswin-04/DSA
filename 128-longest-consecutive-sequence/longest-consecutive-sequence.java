class Solution {
    public int longestConsecutive(int[] nums) {
        
        Set<Integer> set = new HashSet<>();
        
        for(int num: nums) {
            set.add(num);
        }

        int maxCnt = 0;

        for(int num: set) {
            if(set.contains(num-1)) continue;

            int cnt = 1;
            int val = num+1;
            while(set.contains(val)) {
                val++;
                cnt++;
            }

            maxCnt = Math.max(maxCnt, cnt);
        }

        return maxCnt;
    }
}