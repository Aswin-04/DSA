#include<bits/stdc++.h>
using namespace std;


// TC --> O(log10(n))
bool isArmstrong(int n) {

    int num = n;
    int len = to_string(n).length();
    int sum = 0;
    int lastDigit;
    while(n > 0) {
        lastDigit = n%10;
        sum = sum + pow(lastDigit, len);
        n/=10;
    }

    return sum == num ? true : false;
}

int main() {

    int n;
    cin >> n;
    
    if(isArmstrong(n)) {
        cout << "The given number is a Armstrong Number";
    }

    else {
        cout << "The given number is not a Armstrong Number";
    }

    return 0;
}
