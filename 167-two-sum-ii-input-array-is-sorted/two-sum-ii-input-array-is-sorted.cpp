class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;

        while(j < numbers.size()) {
            int sum = numbers[i]+numbers[j];
            if(sum == target) return {i+1, j+1};
            else if(sum > target) j--;
            else i++;
        }

        return {-1, -1};
    }
};