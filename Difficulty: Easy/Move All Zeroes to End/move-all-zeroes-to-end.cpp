// User function template for C++
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int i=0;
        int n = arr.size();
        while(i < n && arr[i] != 0) {
            i++;
        }
        
        int j=i+1;
        while(j < n) {
            if(arr[j] != 0) {
                swap(arr[i], arr[j]);
                i++;
            }
            j++;
        }
    }
};