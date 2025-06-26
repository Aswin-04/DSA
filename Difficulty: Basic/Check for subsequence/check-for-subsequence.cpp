
class Solution {
  public:
    bool isSubSequence(string A, string B) {
        // code here
        if(A.size() > B.size()) return false;
        
        int ptrA=0;
        int ptrB=0;
        
        while(ptrA < A.size() && ptrB < B.size()) {
            if(A[ptrA] == B[ptrB]) ptrA++;
            ptrB++;
        }
        
        if(ptrA < A.size()) return false;
        return true;
        
        
    }
};