class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i=0;
        int j=1;\
        int n = arr.size();

        while(j < n) {
            if(arr[j] > arr[i]) {
                swap(arr[i+1], arr[j]);
                i++;
            }
            j++;
        }
        return i+1;
    }
};