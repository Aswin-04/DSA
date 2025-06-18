class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        unordered_map<int, int> hashWindow;

        for(int i=0; i < k; i++) {
            maxHeap.push(nums[i]);
            hashWindow[nums[i]] = i;
        }

        int l=1;
        int r=k;
        int n=nums.size();
        vector<int> maxWindow;
        maxWindow.push_back(maxHeap.top());

        while(r < n) {
            maxHeap.push(nums[r]);
            hashWindow[nums[r]] = r;

            while(!maxHeap.empty()) {
                int top = maxHeap.top();
                int idx = hashWindow[top];

                if(idx < l) maxHeap.pop();
                else break;
            }

            maxWindow.push_back(maxHeap.top());
            l++;
            r++;
        }

        return maxWindow;
    }
};


