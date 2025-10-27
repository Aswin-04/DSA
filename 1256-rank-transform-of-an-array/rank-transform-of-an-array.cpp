class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr.begin(), arr.end());
        map<int, int> mpp;
        int n = arr.size();
        sort(temp.begin(), temp.end());
        vector<int> res(n);
        int idx = 0;
        for(int i=0; i < n; i++) {
            if(mpp.find(temp[i]) == mpp.end()) {
                mpp[temp[i]] = idx;
                idx++;
            }
        }

        for(int i=0; i < n; i++) {
            res[i] = mpp[arr[i]]+1;
        }
        return res;
    }

};