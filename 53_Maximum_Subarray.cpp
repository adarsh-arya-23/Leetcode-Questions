/*

Algorithm: Brute Force
Time Complexity: O(n^2)
Space Complexity: O(1)
Algorithm Explanation:
1. We initialize a variable `res` to store the maximum sum, starting with the first element of the array.
2. We use two nested loops to iterate through all possible subarrays of the input array `nums`.
   - The outer loop starts from the first element and goes to the end of the array.
    - The inner loop starts from the current index of the outer loop and goes to the end of the array, calculating the sum of the current subarray. 
3. We update the `res` variable with the maximum sum found so far.

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        for(int i = 0 ; i < nums.size() ; i++){
            int restSum = 0;
            for(int j = i ; j < nums.size() ; j++){
                restSum = restSum + nums[j];
                res = max(restSum, res);
            }
        }
        return res;
    }
};
*/

// Kadane's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int current_max = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            current_max = max(nums[i], current_max + nums[i]);
            max_so_far = max(max_so_far, current_max);
        }
        return max_so_far;
    }
};
int main() {
    Solution s;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << s.maxSubArray(nums) << endl;
    return 0;
}