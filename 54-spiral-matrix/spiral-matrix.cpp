class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        int top=0;
        int right=0;
        int left = m-1;
        int bottom = n-1;

        while(top <= bottom && right <= left) {
            for(int j=top; j <= bottom; j++) {
                ans.push_back(matrix[right][j]);
            }
            right++;

            if(right > left) break;
            for(int i=right; i <= left; i++) {
                ans.push_back(matrix[i][bottom]);
            }
            bottom--;

            if(top > bottom) break;
            for(int j=bottom; j >= top; j--) {
                ans.push_back(matrix[left][j]);
            }
            left--;

            for(int i=left; i >= right; i--) {
                ans.push_back(matrix[i][top]);
            }
            top++;

        }

        return ans;
    }

    
};