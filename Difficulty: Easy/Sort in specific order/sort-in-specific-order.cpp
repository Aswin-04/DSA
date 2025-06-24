class Solution {
  public:
    void sortIt(vector<long long>& arr) {
        // code here.
        int n = arr.size();
        int l = 0;
        int r = arr.size()-1;
        
        while(l < r) {
            if(arr[l]&1) l++;
            else if(arr[r]%2 == 0) r--;
            else {
                swap(arr[l], arr[r]);
                l++;
                r--;
            }
        }
        
        int partition = (l < n && arr[l]%2 == 1) ? l+1 : l; 
        
        if(r != -1) sort(arr.begin(), arr.begin()+partition, greater<long long>());
        if(l != n) sort(arr.begin()+partition, arr.end());
    }
};