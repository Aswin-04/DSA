// Function to locate the occurrence of the string x in the string s.
class Solution {
  public:
    int firstOccurence(string &txt, string &pat) {
        // Your code here
        
        for(int i=0; i < txt.size(); i++) {
            if(txt[i] != pat[0]) continue;
            int ptr1 = i;
            int ptr2 = 0;
            
            while(ptr1 < txt.size() && ptr2 < pat.size()) {
                if(txt[ptr1] != pat[ptr2]) break;
                ptr1++;
                ptr2++;
            }
            
            if(ptr2 == pat.size()) return i;
        }
        
        return -1;
        
    }
};