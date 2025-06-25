#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(auto &i: arr) cin >> i;
    
    unordered_map<int, int> freqHash;
    for(auto i: arr) {
        freqHash[i]++;
    }
    
    map<int, set<int>> freqHashSet;
    for(auto it = freqHash.begin(); it != freqHash.end(); it++) {
        int val = it->first;
        int freq = it->second;
        freqHashSet[freq].insert(val);
    }
    
    vector<int> ans;
    for(auto it = freqHashSet.rbegin(); it != freqHashSet.rend(); it++) {
        int freq = it->first;
        set<int> st = it->second;
        for(int val: st) {
            for(int i=0; i < freq; i++) {
                ans.push_back(val);
            }
        }
    }
    
    for(int val: ans) {
        cout << val << " ";
    }
    cout << endl;
    
}

int main() {
	//code here
	int t;
	cin >> t;
	
	while(t--) {
	    solve();
	}
	return 0;
}