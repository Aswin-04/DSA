class Solution {
  public:
    void printDiamond(int n) {
        // code here
        for(int i=1; i <= n; i++) {
            
            for(int j=i; j <= n-1; j++) {
                cout << " ";
            }
            
            for(int j=1; j <= i; j++) {
                cout << "* ";
            }
            
            cout << endl;
        }
        
        for(int i=1; i <= n; i++) {
            
            for(int j=1; j <= i-1; j++) {
                cout << " ";
            }
            
            for(int j=i; j <= n; j++) {
                cout << "* ";
            }
            
            cout << endl;
        }
        
    }
};