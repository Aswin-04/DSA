class Solution {
    public int subarraySum(int[] nums, int k) {
        int cnt = 0;
        HashMap<Integer, Integer> map = new HashMap<>();

        int sum = 0;
        map.put(0, 1);
        for (int num : nums) {
            sum += num;
            int freq = map.getOrDefault(sum-k, 0);
            if (freq != 0)
                cnt+=freq;
                
            map.put(sum, map.getOrDefault(sum, 0)+1);
        }

        return cnt;

    }
}