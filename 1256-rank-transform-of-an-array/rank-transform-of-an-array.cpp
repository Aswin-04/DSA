class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp(arr);
        map<int, int> mpp;
        vector<int> res;

        sort(temp.begin(), temp.end());

        int n = arr.size();
        for(int i=0; i < n; i++) {
            if(mpp.find(temp[i]) == mpp.end()) {
                mpp[temp[i]] = mpp.size()+1;
            }
        }

        for(int i=0; i < n; i++) {
            res.push_back(mpp[arr[i]]);
        }
        return res;
    }

};