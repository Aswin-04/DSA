#include<bits/stdc++.h>
using namespace std;



// vector<int> getFrequencies(vector<int>& v) {
//     // Write Your Code Here
//     unordered_map<int,int> ans;
//     int n = v.size();
//     int maxFre = 0;
//     int minFre = n;
//     int maxEle = 0;
//     int minEle = 0;
//     for(int i=0; i < n; i++) {
//         ans[v[i]]++;

//     }

//     for (auto it: ans) {

//     if(it.second > maxFre) maxEle = it.first;
//     if (it.second < minFre) minEle = it.first;
//     }




//     vector<int> ans_vec;
//     ans_vec.push_back(maxEle);
//     ans_vec.push_back(minEle);

//     return ans_vec;
// }


// int main() {
    
//     vector<int> nums = {1, 2, 3, 1, 1, 4};
//     unordered_map<int,int> ans;
//         for(int i=0; i < nums.size(); i++) {
//         ans[nums[i]]++;
//     }

//     for (auto it : ans) {
//         cout << it.first << "-->" << it.second << endl; 
//     }

//     cout << ans[1];
//     vector<int> answer = getFrequencies(nums);
//     for (auto it : answer) {
//         cout << it << " ";
//     }

// }

// vector<int> rotateArray(vector<int> &arr, int k) {
//     // Write your code here.
//     vector<int> temp;
//     int n = arr.size();
//     k = k%n;
//     for(int i=0; i < k; i++) {
//         temp.push_back(arr[i]);
//     }

//     for(int i=k; i < n; i++) {
//         arr[i-k] = arr[i];
//     }

//     for(int i=n-k; i < n; i++) {
//         arr[i] = temp[i - (n-k) ];
//     }

//     return arr;
// }

vector<int> intersect(vector<int> arr1, vector<int> arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0;
    int j = 0;
    vector<int> answer;

    while(i < n1 && j < n2) {

        if(arr1[i] < arr2[j]) {
            i++;
        }

        else if(arr2[j] < arr1[i]) {
            j++;
        }

        else if(arr1[i] == arr2[j]) {
            if(answer.empty() || answer.back() != arr1[i]) {
                answer.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    return answer;
}
int main() {
    // vector<int> arr1 = {1, 2, 2, 3, 3, 4, 5, 6};
    // vector<int> arr2 = {2, 3, 3, 5, 6, 7};

    // vector<int> arr1 = {0, 0,0 ,0, 0, 0, 0, 1};
    // vector<int> arr2 = {0, 1, 2, 3, 4, 5};
    
    // vector<int>ans = intersect(arr1, arr2);
    // rotateArray(arr, 2);
    // for(auto it: arr) {
    //     cout << it << " ";
    // }

    // for(auto it: ans) {
    //     cout << it << " ";
    // }

    // auto xor1 = 1^2^3^4^5;
    // cout << xor1 << endl;

    // auto xor2 = 0;
    // for(int i=1; i <=5; i++) {
    //     xor2 = xor2^i;
    //     cout << i << "-->" << xor2 << endl;
    // }

    cout << (7%3);



}
