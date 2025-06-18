class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // TC --> O(n logn)
        // SC --> O(n)
        
        priority_queue<pair<int, int>> maxHeap;
        unordered_map<int, int> hashWindow;

        for(int i=0; i < k; i++) {
            maxHeap.push({nums[i], i});
        }

        int l=1;
        int r=k;
        int n=nums.size();
        vector<int> maxWindow;
        maxWindow.push_back(maxHeap.top().first);

        while(r < n) {
            maxHeap.push({nums[r], r});

            while(!maxHeap.empty()) {
                int idx = maxHeap.top().second;
                if(idx < l) maxHeap.pop();
                else break;
            }

            maxWindow.push_back(maxHeap.top().first);
            l++;
            r++;
        }

        return maxWindow;
    }
};


