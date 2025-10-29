class Solution {
  public:
    void relativeSort(vector<int>& a1, vector<int>& a2) {
        
        set<int> seen;
        map<int, int> freq;
        vector<int> res;
        for(const int &val: a1) freq[val]++;
        for(const int &val: a2) {
            if(seen.count(val)) continue;
            for(int i=0; i < freq[val]; i++) res.push_back(val);
            seen.insert(val);
        }
        
        int idx = res.size();
        for(const int &val: a1) {
            if(seen.count(val)) continue;
            res.push_back(val);
        }
        
        if(idx < res.size()) {
            sort(res.begin()+idx, res.end());
        }
        
        a1 = res;
        
    }
};
