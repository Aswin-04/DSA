#include<bits/stdc++.h>
using namespace std;

// Brute force approach 
// TC --> O(min(n1, n2))

int gcd1(int n1, int n2) {

    int gcd = 1;

    for(int i=1; i <= min(n1, n2); i++) {
        if(n1%i == 0 && n2%i == 0) {
            gcd = i;
        }
    }

    return gcd;
}

//Optimal approach
// TC --> O(log min(n1, n2))

int gcd2(int n1, int n2) {

    while(n1 != 0 && n2 != 0) {
        
        if(n1 > n2) n1 = n1%n2;
        else n2 =  n2%n1;
    }

    return n1 == 0 ? n2 : n1;

    return 0;
}


int main() {
    
    int n1, n2;
    cin >> n1 >> n2;
    cout << "GCD is : " << gcd1(n1, n2);
    cout << endl;
    cout << "GCD is : " << gcd2(n1, n2);

    return 0;
}
