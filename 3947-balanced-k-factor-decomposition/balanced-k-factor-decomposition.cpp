class Solution {
public:
    vector<int> minDifference(int n, int k) {
        vector<int> divs;
        vector<int> chosen;
        vector<int> ans;
        int min_diff = INT_MAX;

        get_divisors(n, divs);
        backtrack(0, n, k, 1, min_diff, chosen, divs, ans);

        return ans;
    }

private: 
    void get_divisors(int n, vector<int>& divs) {
        for(int i=1; i*i <= n; i++) {
            if(n%i == 0) {
                divs.push_back(i);
                if(i != n/i) divs.push_back(n/i);
            }
        }
        sort(divs.begin(), divs.end());
    }

    int get_diff(vector<int>& chosen) {
        int maxi = *max_element(chosen.begin(), chosen.end());
        int mini = *min_element(chosen.begin(), chosen.end());
        return maxi - mini;
    }

    void backtrack(int idx, int n, int k, int product, int& min_diff, vector<int>& chosen, vector<int>& divs, vector<int>& ans) { 
        // pruning

        // base case
        if(chosen.size() == k) {
            if(product == n) {
                int diff = get_diff(chosen);
                if(diff < min_diff) {
                    ans = chosen;
                    min_diff = diff;
                }
            }
            return;
        }

        // choice
        for(int i=idx; i < divs.size(); i++) {
            if(1ll*product*divs[i] > n) break;  // prune
            chosen.push_back(divs[i]); // insert and move to next 
            backtrack(i, n, k, product*divs[i], min_diff, chosen, divs, ans); // move
            chosen.pop_back(); // revert
        }
    }
};