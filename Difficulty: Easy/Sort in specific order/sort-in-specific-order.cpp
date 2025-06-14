class Solution {
  public:
    void sortIt(vector<long long>& arr) {
        // code here.
        int n = arr.size();
        int i=0;
        int j = n-1;
        
        while(i <= j) {
            if(arr[i]&1) i++;
            else if(arr[j]%2 == 0) j--;
            else {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        
        sort(arr.begin(), arr.begin()+i, greater<long long>());
        sort(arr.begin()+i, arr.end());
    }
};