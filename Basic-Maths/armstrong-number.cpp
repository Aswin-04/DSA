#include<bits/stdc++.h>
using namespace std;

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
    cout << isArmstrong(n);

    return 0;
}
