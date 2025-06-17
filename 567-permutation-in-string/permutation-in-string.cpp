class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        // TC --> O(n2) 
        // SC --> O(52);
        int n1 = s1.size();
        int n2 = s2.size();

        if(n1 > n2) return false;
        
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(int i=0; i < n1; i++) {
            freq2[s2[i]-'a']++;
            freq1[s1[i]-'a']++;
        }


        int l=0;
        int r=n1-1;

        freq2[s2[r]-'a']--;
        while(r < n2) {
            freq2[s2[r]-'a']++;
            int flag = 0;
            for(int i=0; i < 26; i++) {
                if(freq1[i] != freq2[i]) {
                    flag = 1;
                    break;
                } 
            }

            if(!flag) return true;
            freq2[s2[l]-'a']--;
            l++;
            r++; 
        }

        return false;
    }
};