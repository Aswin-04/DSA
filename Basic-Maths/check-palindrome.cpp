#include<bits/stdc++.h>
using namespace std;

// TC --> O(log10(n))
bool checkPalindrome(int n) {
    int givenNum = n;
    int lastDigit, revNum = 0;

    while(n > 0) {
        lastDigit = n%10;
        revNum = (revNum * 10) + lastDigit;
        n/=10;
    }

    if(revNum == givenNum) return true;
    else return false;
}
int main() {

    int n;
    cin >> n;
    cout << checkPalindrome(n);

    return 0;
}
