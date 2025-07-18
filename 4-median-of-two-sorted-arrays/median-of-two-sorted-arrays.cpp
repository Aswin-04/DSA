class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2) {
            swap(nums1, nums2);
            swap(n1, n2);
        }

        int low = 0;
        int high = n1;
        int left = (n1+n2) >> 1;

        while(low <= high) {
            int mid1 = low + ((high-low) >> 1);
            int mid2 = left-mid1;

            int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            if(mid1-1 >= 0) l1 = nums1[mid1-1];
            if(mid2-1 >= 0) l2 = nums2[mid2-1];
            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];

            if(l1 > r2) high = mid1-1;
            else if(l2 > r1) low = mid1+1;
            else {
                if((n1+n2)&1) return min(r1, r2);
                else return ((double)(max(l1, l2)+min(r1, r2))) / 2.0;
            }
        }

        return 0;
    }
};