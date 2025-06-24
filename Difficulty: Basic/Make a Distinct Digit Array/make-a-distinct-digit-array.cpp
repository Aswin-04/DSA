
class Solution {
  public:
    vector<int> common_digits(vector<int> nums) {
        // Code here
        vector<int> digitsHash(10, 0);
        vector<int> answer;
        
        for(int val: nums) {
        int temp = val;
        while(temp) {
          int rem = temp%10;
          digitsHash[rem] = 1;
          temp/=10;
        }
        }
        
        for(int i=0; i < digitsHash.size(); i++) {
        if(digitsHash[i] == 0) continue;
        answer.push_back(i); 
        }
        
        return answer;
    }
};