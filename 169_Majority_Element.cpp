/*

Approach I: Hash Map
1. Create a hash map to count the occurrences of each element in the array.
2. Iterate through the hash map to find the element with the highest count.
3. Return the element with the highest count as the majority element.
Time Complexity: O(n) - We traverse the array once to fill the hash map and then traverse the hash map to find the majority element.
Space Complexity: O(n) - In the worst case, all elements in the array are unique, and we need to store each element in the hash map.

Approach II: Sorting
1. Sort the array.
2. The majority element will be the middle element of the sorted array, since it appears more than n/2 times.
Time Complexity: O(n log n) - Sorting the array takes O(n log n) time
Space Complexity: O(1) - We are sorting the array in place, so we do not require additional space.
*/

/*APPROACH I*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size = nums.size();
        map<int, int> mp;
        for(int i : nums){
            mp[i]++;
        }
        int max = 0;
        int res = -1;
        for (const auto& pair : mp) {
            if(max < pair.second){
                max = pair.second;
                res = pair.first;
            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << sol.majorityElement(nums) << endl; // Output: 2
    return 0;
}


/*APPROACH II
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:    
    int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << sol.majorityElement(nums) << endl; // Output: 2
    return 0;
}
*/