#include<bits/stdc++.h>
using namespace std;

int main() {

    int num, revNum = 0;
    cin >> num;

    while(num > 0) {
        int lastDigit = num%10;
        if(lastDigit == 0) continue;
        revNum  = (revNum * 10) + lastDigit;
        num/=10; 
    }
    cout << revNum;

    return 0;
}