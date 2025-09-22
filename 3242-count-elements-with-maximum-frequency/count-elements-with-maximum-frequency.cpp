class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>mpp;
        for(int i=0; i<nums.size(); i++) {
            mpp[nums[i]]++;
        }
        int k=-1;
        int sum=0;
        for(auto i = mpp.begin(); i != mpp.end(); i++) {
            k=max(k, i->second);
        }
        for(auto i = mpp.begin(); i != mpp.end(); i++) {
            if(i->second == k ) {
                sum = sum + k;
            }
        }
        return sum;
    }
};