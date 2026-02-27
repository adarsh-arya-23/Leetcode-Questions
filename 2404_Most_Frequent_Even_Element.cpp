/*

Approach:
1. We will first create a vector to store all the even elements from the input vector.
2. We will then create a map to count the frequency of each even element.
3. We will iterate through the map to find the even element with the highest frequency. If there are multiple even elements with the same frequency, we will return the smallest one.
4. If there are no even elements, we will return -1.

*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        vector<int> evenElements;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] % 2 == 0){
                evenElements.push_back(nums[i]);
            }
        }
        map<int, int> mp;
        for(auto i : evenElements){
            mp[i]++;
        }
        int max = 0;
        int ans = -1;
        for(auto i : mp){
            if(i.second > max){
                max = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> nums = {0,1,2,2,4,4,1};
    cout << s.mostFrequentEven(nums) << endl;
    return 0;
}