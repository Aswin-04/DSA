class Solution {
public:
    
    // TC --> O(4N)
    // SC --> O(N)

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n, -1);

        for(int i=n-1; i>=0; i--) {  // O(N)
            while(!st.empty() && st.top() <= nums[i]) { // O(N) throughout the problem
                st.pop();
            }
            st.push(nums[i]);
        }

        for(int i=n-1; i>=0; i--) {  // O(N)
            while(!st.empty() && st.top() <= nums[i]) { // O(N) throughout the problem
                st.pop();
            }
            
            if(!st.empty()) ans[i] = st.top();
            st.push(nums[i]);
        }

        return ans;
    }
};