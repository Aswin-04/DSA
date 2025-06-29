class Solution {
  public:
    int findExtra(vector<int>& a, vector<int>& b) {
        // add code here.
        int i;
        
        for(i=0; i < b.size(); i++) {
            if(a[i] != b[i]) return i;
        }
        
        return i;
    }
};