class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int hs = INT_MAX;
        int he = 0;
        int vs =  INT_MAX;
        int ve = 0;
        int n = grid.size();
        for(int i=0; i < grid.size(); i++) {
            for(int j=0; j < grid[0].size(); j++) {
                if(grid[i][j] == 0) continue;
                hs = min(hs, j);
                he = max(he, j);
                vs = min(vs, i);
                ve = max(ve, i);
            }
        }

        return (he-hs+1) * (ve-vs+1);
    }
};