class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        // TC --> O(n1*n2*n1log(n1)) 
        // SC --> O(n1);
        int n1 = s1.size();
        int n2 = s2.size();
        sort(s1.begin(), s1.end());
        for(int i=0; i <= n2-n1; i++) {
            string str = "";
            for(int j=i; j < i+n1; j++) {
                str+=s2[j];
            }

            sort(str.begin(), str.end());

            if(s1 == str) return true;
        }

        return false;
    }
};