//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string encode(vector<string>& s) {
        // code here
        string encoded_str = "";
        for(int i=0; i < s.size()-1; i++) {
            encoded_str+=(s[i] + '\n');
        }
        encoded_str+=s[s.size()-1];
        
        return encoded_str;
        
    }
    

    vector<string> decode(string& s) {
        
        // code here
        stringstream ss(s);
        vector<string> tokens;
        string token;
        
        while(getline(ss, token, '\n')) {
            tokens.push_back(token);
        }
        
        return tokens;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // To ignore the newline after the number of test cases

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        string word;
        vector<string> s;

        while (ss >> word) {
            s.push_back(word);
        }

        Solution obj;
        string encodedString = obj.encode(s);
        vector<string> decodedStrings = obj.decode(encodedString);

        for (string x : decodedStrings) {
            cout << x << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends