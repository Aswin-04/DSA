//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long int xor1 = 0;
        for(int i=0; i < N; i++) {
            xor1^=Arr[i];
        }
        
        long long int last_set_bit = (xor1&(xor1-1))^xor1;
        
        long long int b1=0, b2=0;
        int pos = log2(last_set_bit);
        
        for(int i=0; i < N; i++) {
            if((Arr[i]>>pos)&1) b1^=Arr[i];
            else b2^=Arr[i];
        }
        
        
        if(b1 < b2) {
            b1 = b1^b2;
            b2 = b1^b2;
            b1 = b1^b2;
        }
        
        return {b1, b2};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends