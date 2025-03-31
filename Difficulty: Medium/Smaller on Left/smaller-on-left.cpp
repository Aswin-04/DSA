//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> Smallestonleft(int arr[], int n);

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        int arr[n + 1];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> b;
        b = Smallestonleft(arr, n);
        for (int i = 0; i < n; i++)
            cout << b[i] << " ";

        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends

set<int>::iterator get_lower_bound(set<int> &st, int val) {
    
    auto low = st.begin();
    auto high = st.end();
    auto ans = st.end();
    while(low != high) {
        auto mid = next(low, distance(low, high)/2);
        if(*mid >= val) high = mid;
        else low = next(mid);
    }
    
    return low;
}

vector<int> Smallestonleft(int arr[], int n) {
    // Complete the function
    vector<int> ans;
    set<int> st;
    for(int i=0; i < n; i++) {
        st.insert(arr[i]);
        auto it = get_lower_bound(st, arr[i]);
        if(it == st.begin()) ans.push_back(-1);
        else {
            --it;
            ans.push_back(*it);
        }
        
    }
    
    return ans;
    
}