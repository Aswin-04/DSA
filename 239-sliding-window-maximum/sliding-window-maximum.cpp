class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // TC --> O(n logn)
        // SC --> O(n)

        priority_queue<pair<int, int>> maxHeap;
        vector<int> maxWindow;

        for(int i=0; i < nums.size(); i++) {
            maxHeap.push({nums[i], i});
            if(i >= k-1) {
                while(maxHeap.top().second < i-k+1) {
                    maxHeap.pop();
                }
                maxWindow.push_back(maxHeap.top().first);
            }
        }
        return maxWindow;
    }
};


