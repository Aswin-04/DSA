class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxEl = 0;
        for(int val: piles) {
            maxEl = max(maxEl, val);
        }

        int l=1, r=maxEl;

        while(l <= r) {
            int m = (l+r)/2;
            long long h_cnt = 0;
            for(int val: piles) {
                h_cnt+=((1LL*val+m-1)/m);
            }

            if(h_cnt <= h) r=m-1;
            else l=m+1;
        }

        return l;
    }
};