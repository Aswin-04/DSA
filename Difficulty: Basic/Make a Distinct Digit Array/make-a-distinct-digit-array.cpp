
class Solution {
  public:
    vector<int> common_digits(vector<int> nums) {
        // Code here
        set<int> st;
        for(int i=0; i < nums.size(); i++) {
            int num = nums[i];
            while(num > 0) {
                st.insert(num%10);
                num/=10;
            }
        }
        
        return vector<int>(st.begin(), st.end());
        
    }
};