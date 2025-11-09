class Solution {
  private:
    bool bs(vector<int>& arr, int target) {
        int low = 0;
        int high = arr.size()-1;
        
        while(low <= high) {
            int mid = low + ((high-low) >> 1);
            if(arr[mid] < target) low = mid+1;
            else if(arr[mid] > target) high = mid-1;
            else return true; 
        }
        
        return false;
    }
    
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        
        int low = 0;
        int high = mat.size()-1;
        int m = mat[0].size()-1;
        
        while(low <= high) {
            int mid = low + ((high-low)>>1);
            int strt = mat[mid][0];
            int end = mat[mid][m];
            
            if(x >= strt && x <= end) return bs(mat[mid], x);
            else if(x > end) low = mid+1;
            else high = mid-1;
        }
        
        return false;
    }
};