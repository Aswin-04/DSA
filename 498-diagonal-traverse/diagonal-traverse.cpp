class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> temp(n+m-1);
        for(int i=0; i < n; i++) {
            int j;
            for(j=0; j < m; j++) {
                temp[i+j].push_back(mat[i][j]);
            }
        }

        vector<int> res;
        for(int i=0; i < n+m-1; i++) {
            int sz = temp[i].size();
            if(i&1) {
                for(int j=0; j < sz; j++) {
                    res.push_back(temp[i][j]);
                }
            }
            else {
                for(int j=sz-1; j >= 0; j--) {
                    res.push_back(temp[i][j]);
                }
            }
        }

        return res;
    }
};