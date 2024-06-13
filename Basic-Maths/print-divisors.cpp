#include<bits/stdc++.h>
using namespace std;
// Brute Force Approach
// TC --> O(N/2)
// 
void printDivisors1(int n) {
    int val = 2;
    vector<int> divisors;
    divisors.emplace_back(1);
    while(val <= (n/2)) {
        if(n%val == 0) {
            divisors.emplace_back(val);
        }
        val++;
    }
    divisors.emplace_back(n);

    cout << "Divisors of " << n << " are ";
    for(auto it : divisors) {
        cout << it << " ";
    }
}

//Optimal Approach   
// TC --> O(sqrt(n)) + O(n log(n)) + O(n) 
void printDivisors2(int n) {

    int sqrtN = sqrt(n); 
    vector<int> v;

    // O(sqrt(n)) , where n is the input
    // we can also use (i*i <= n) instead of sqrt(N)
    for(int i=1; i <= sqrtN; i++) {
        if(n%i == 0) {
            v.emplace_back(i);

            if(n/i != i) {
                v.emplace_back(n/i);
            }
        }
    }

    // O(n log(n)) where n is the no of factors
    sort(v.begin(), v.end());

    // O(n) , where n is the no of factors
    cout << "Divisors of " << n << " are ";
    for(auto it : v) {
        cout << it << " ";
    }

}

int main() {

    int n;
    cin >> n;

    printDivisors1(n);
    cout << endl;
    printDivisors2(n);

    return 0;
}
