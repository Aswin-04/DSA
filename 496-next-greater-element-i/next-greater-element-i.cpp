class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;

        for(int i=0; i < n1; i++) {
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            int idx = distance(nums2.begin(), it);
            bool f = 0;
            for(int j=idx+1; j < n2; j++) {
                if(nums2[j] > nums1[i]) {
                    ans.push_back(nums2[j]);
                    f=1;
                    break;
                }
            }

            if(!f) ans.push_back(-1);
        }

        return ans;
    }
};