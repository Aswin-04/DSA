class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        
        map<int, int> freq;
        for(int &i: a) freq[i]++;
        
        for(int &i: b) {
            if(freq.find(i) != freq.end() && freq[i] > 0) freq[i]--;
            else return false;
        }
        
        return true;
    }
};