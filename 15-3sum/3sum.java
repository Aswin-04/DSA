class Solution {
    public List<List<Integer>> threeSum(int[] nums) {

        int n = nums.length;        
        List<List<Integer>> res = new ArrayList<>();

        Arrays.sort(nums);

        for(int i=0; i < n; i++) {

            int left = i+1;
            int right = n-1;
            int target = -nums[i];

            if(i != 0 && nums[i-1] == nums[i]) continue;

            while(left < right) {
                int sum = nums[left] + nums[right];
                if(sum == target) {
                    res.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    left++;
                    right--;

                    while(left < right && nums[left-1] == nums[left]) left++;
                    while(left < right && nums[right+1] == nums[right]) right--;
                }

                else if(sum < target) left++;
                else right--;
            }
        }

        return res;
    }
}