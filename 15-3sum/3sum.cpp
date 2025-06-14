class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        unordered_map<int, int> count;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> answer;
        for(int num: nums) {
            count[num]++;
        }

        for(int i=0; i < n; i++) {
            count[nums[i]]--;
            if(i > 0 && nums[i-1] == nums[i]) continue;

            for(int j=i+1; j < n; j++) {
                count[nums[j]]--;
                if(j > i+1 && nums[j-1] == nums[j]) continue;
                int target = -(nums[i]+nums[j]);
                if(count[target] > 0) {
                    answer.push_back({nums[i], nums[j], target});
                }
            }

            for(int j=i+1; j < n; j++) {
                count[nums[j]]++;
            }
        }

        return answer;
    }
};