class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int res = 1e9;

        for(int i=0; i < m; i++) {
            int one = minArea(0, i, 0, n-1, grid);
            for(int j=0; j < n; j++) {
                int two = minArea(i+1, m-1, 0, j, grid);
                int three = minArea(i+1, m-1, j+1, n-1, grid);
                cout << one << " " << two << " " << three << endl;
                res = min(res, one + two + three);
            }
        }

        for(int j=0; j < n; j++) {
            int one = minArea(0, m-1, 0, j, grid);
            for(int i=0; i < m; i++) {
                int two = minArea(0, i, j+1, n-1, grid);
                int three = minArea(i+1, m-1, j+1, n-1, grid);
                cout << one << " " << two << " " << three << endl;
                res = min(res, one+two+three);
            }
        }

        for(int j=n-1; j >= 0; j--) {
            int one = minArea(0, m-1, j, n-1, grid);
            for(int i=0; i < m; i++) {
                int two = minArea(0, i, 0, j-1, grid);
                int three = minArea(i+1, m-1, 0, j-1, grid);
                res = min(res, one+two+three);
            }
        }

        for(int i=m-1; i >=0; i--) {
            int one = minArea(i, m-1, 0, n-1, grid);
            for(int j=0; j < n; j++) {
                int two = minArea(0, i-1, 0, j, grid);
                int three = minArea(0, i-1, j+1, n-1, grid);
                res = min(res, one+two+three);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=i+1;j<m;j++){
                int one = minArea(0, i, 0, n-1, grid);
                int two = minArea(i+1, j, 0, n-1, grid);
                int three = minArea(j+1, m-1, 0, n-1, grid);
                res = min(res, one + two + three);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int one = minArea(0, m-1, 0, i, grid);
                int two = minArea(0, m-1, i+1, j, grid);
                int three = minArea(0, m-1, j+1, n-1, grid);
                res = min(res, one + two + three);
            }
        }

        return res;

    }
private:
    int minArea(int strt_i, int end_i, int strt_j, int end_j, vector<vector<int>>& grid) {

        int strt_row = 1e9;
        int end_row = -1;
        int strt_col = 1e9;
        int end_col = -1;
        bool found = false;

        for(int i=strt_i; i <= end_i; i++) {
            for(int j=strt_j; j <= end_j; j++) {
                if(grid[i][j] == 0) continue;
                strt_row = min(strt_row, i);
                end_row = max(end_row, i);
                strt_col = min(strt_col, j);
                end_col = max(end_col, j);
                found = true;
            }
        }

        return found ? (end_row-strt_row+1) * (end_col-strt_col+1) : 0;
    }
};