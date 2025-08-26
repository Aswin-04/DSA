class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int m = dimensions.size();
        int maxArea = 0;
        int maxD = 0;
        for(int i=0; i < m; i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            int d = l*l + w*w;
            
            if(d > maxD || d == maxD && l*w > maxArea) {
                maxD = d;
                maxArea = l*w;
            }
        }

        return maxArea;
    }
};