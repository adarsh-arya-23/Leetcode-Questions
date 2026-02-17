/*

Approach Used: Brute Force
Time Complexity: O(n^2)
Space Complexity: O(1)

Procedure:
    -> We will use two nested loops to iterate through the array.
    -> The outer loop will start from the first element and the inner loop will start from the next element of the outer loop.
    -> We will check if the sum of the elements at the current indices of the outer and inner loops is equal to the target.
    -> If it is equal, we will return the indices of the two elements as a vector
    -> If it is not equal, we will continue to the next iteration of the inner loop.


*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int>ar1;
        for(int i = 0 ; i < size ; i++){
            for(int j = 0 ; j < i ; j++){
                if(nums[i]+nums[j] == target){
                    ar1.push_back(i);
                    ar1.push_back(j);
                    return ar1;
                }
                else{
                    continue;
                }
            }
        }
        return ar1;
    }
};

int main(){
    Solution s;
    vector<int>nums = {2,7,11,15};
    int target = 9;
    vector<int>result = s.twoSum(nums,target);
    for(int i = 0 ; i < result.size() ; i++){
        cout<<result[i]<<" ";
    }
}