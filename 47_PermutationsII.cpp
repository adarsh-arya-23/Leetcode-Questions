/*

Approach: Backtracking with Sorting and Set
Time Complexity: O(n! * n) - There are n! permutations and generating each permutation takes O(n) time. The set operations also contribute to the time complexity.
Space Complexity: O(n) - The space used by the recursion stack is O(n) in the worst case when all elements are used in the current permutation. The set also uses additional space to store unique permutations.
Procedure:
1. Sort the input array to ensure that we start with the smallest lexicographical permutation.
2. Use the next_permutation function to generate the next permutation in place.
3. Insert each generated permutation into a set to ensure uniqueness.
4. After generating all permutations, convert the set back to a vector of vectors to return the result.

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> result;
        vector<vector<int>> result1;
        sort(nums.begin(), nums.end());
        do{
            result.insert(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        for(auto i : result){
            result1.push_back(i);
        }
        return result1;
    }
};
int main(){
    Solution s;
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = s.permuteUnique(nums);
    for(auto& perm : result){
        for(int num : perm){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}