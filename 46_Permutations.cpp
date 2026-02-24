/*

Approach Used: Backtracking
Time Complexity: O(n! * n) - There are n! permutations and generating each permutation takes O(n) time.
Space Complexity: O(n) - The space used by the recursion stack is O(n) in the worst case when all elements are used in the current permutation.
Procedure:
1. Sort the input array to ensure that we start with the smallest lexicographical permutation.
2. Use the next_permutation function to generate the next permutation in place.
3. Continue generating permutations until we have looped through all possible permutations.

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        do{
            result.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return result;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s.permute(nums);
    for(auto& perm : result){
        for(int num : perm){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}