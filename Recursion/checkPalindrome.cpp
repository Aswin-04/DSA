#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s, int i, int len) {
    if(i >= len/2) return true;
    if(s[i] != s[len-i-1]) return false;
    return checkPalindrome(s, i+1, len);
}

int main() {
    
    string s;
    cin >> s;
    int len = s.size();

    cout << checkPalindrome(s, 0, len) << endl;
    
    return 0;
}
