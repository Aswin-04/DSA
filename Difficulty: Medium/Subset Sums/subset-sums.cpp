class Solution {
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> res;
        makeSubsetSum(0, 0, arr, res);
        return res;
    }
    
  private:
    void makeSubsetSum(int idx, int sum, vector<int>& arr, vector<int>& res) {
        
        if(idx == arr.size()) {
            res.push_back(sum);
            return;
        }
        
        sum+=arr[idx];
        makeSubsetSum(idx+1, sum, arr, res);
        sum-=arr[idx];
        makeSubsetSum(idx+1, sum, arr, res);
    }
};