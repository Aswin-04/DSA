class Solution {
public:
    vector<long long> getSubArrayMinimum(vector<int>& nums) {
        int n = nums.size();
        stack<int> st_p, st_n;
        vector<int> left(n);
        vector<int> right(n);
        vector<long long> ans(n);

        for(int i=0; i < n; i++) {
            while(!st_p.empty() && nums[st_p.top()] >= nums[i]) st_p.pop();
            left[i] = st_p.empty() ? i+1 : i-st_p.top();
            st_p.push(i);
        }

        for(int i=n-1; i>= 0; i--) {
            while(!st_n.empty() && nums[st_n.top()] > nums[i]) st_n.pop();
            right[i] = st_n.empty() ? n-i : st_n.top()-i;
            st_n.push(i);
        }

        for(int i=0; i < n; i++) {
            ans[i] = 1LL*nums[i]*left[i]*right[i];
        }

        return ans;
    }

    vector<long long> getSubArrayMaximum(vector<int>& nums) {
        int n = nums.size();
        stack<int> st_p, st_n;
        vector<int> left(n);
        vector<int> right(n);
        vector<long long> ans(n);

        for(int i=0; i < n; i++) {
            while(!st_p.empty() && nums[st_p.top()] <= nums[i]) st_p.pop();
            left[i] = st_p.empty() ? i+1 : i - st_p.top();
            st_p.push(i);
        }

        for(int i=n-1; i>= 0; i--) {
            while(!st_n.empty() && nums[st_n.top()] < nums[i]) st_n.pop();
            right[i] = st_n.empty() ? n-i : st_n.top() - i;
            st_n.push(i);
        }

        for(int i=0; i < n; i++) {
            ans[i] = 1LL*nums[i]*left[i]*right[i];
        }

        return ans;
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<long long> subArrayMaximum = getSubArrayMaximum(nums);
        vector<long long> subArrayMinimum = getSubArrayMinimum(nums); 

        long long maxi = accumulate(subArrayMaximum.begin(), subArrayMaximum.end(), 0LL);
        long long mini = accumulate(subArrayMinimum.begin(), subArrayMinimum.end(), 0LL);

        return maxi-mini;
    }
};