#include<bits/stdc++.h>
using namespace std;

int main() {



    // Brute Force Approach TC --> O(log10(n))
    int num, n, count = 0;
    cin >> num;
    n = num;
    while(n > 0) {
        count++;
        n/=10;
    }
    cout << count << endl;

    //  Optimal Approach TC --> O(1)
    cout << (int)(log10(num) + 1);

    return 0;
}