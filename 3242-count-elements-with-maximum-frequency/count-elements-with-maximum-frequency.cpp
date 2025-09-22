class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }
        int sum=0;
        auto it = *max_element(freq.begin(), freq.end());
        for(int i=0; i<freq.size(); i++) {
            if(freq[i]==it) {
                sum = sum + it;
            }
        }
        return sum; 
    }
};