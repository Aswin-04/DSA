class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // binary search to find the row, where the target may exist
        // TC --> O(logm + logn)
        // SC --> O(1)
        
        int m = matrix.size();
        int n = matrix[0].size();

        int l=0, r = m-1;

        while(l <= r) {
            int mid = (l+r)/2;
            int lb = matrix[mid][0];
            int ub = matrix[mid][n-1];

            if(target < lb) r = mid-1;
            else if(target > ub) l = mid+1;
            else  break;
        }

        if(l > r) return false;

        int row = (l+r)/2;
        l=0; r = n-1;
        while(l <= r) {
            int mid = (l+r)/2;
            if(matrix[row][mid] > target) r=mid-1;
            else if(matrix[row][mid] < target) l=mid+1;
            else return true;
        }

        return false;
    }
};