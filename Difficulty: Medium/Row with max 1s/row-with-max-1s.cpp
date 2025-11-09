// User function template for C++
class Solution {
  private:
    int ub(vector<int>&arr) {
        int low = 0;
        int high = arr.size();
        
        while(low < high) {
            int mid = low + ((high-low) >> 1);
            if(arr[mid] == 0) low = mid+1;
            else high = mid;
        }
        
        return low;
    }
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int ans = -1;
        int maxOnes = 0;
        int n = arr.size();
        int m = arr[0].size();
        for(int i=0; i < n; i++) {
            int idx = ub(arr[i]);
            if(idx != m) {
                if(m-idx > maxOnes) {
                    maxOnes = m-idx;
                    ans = i;
                }
            }
        }
        return ans;
    }
};