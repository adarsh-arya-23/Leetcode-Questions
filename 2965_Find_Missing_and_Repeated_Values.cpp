/*

Approach:
1. We can use an unordered set to keep track of the numbers we have seen in the grid.
2. We iterate through the grid and for each number, we check if it is already in the set. If it is, then we have found the repeated number (let's call it 'a').
3. We also calculate the actual sum of all the numbers in the grid (let's call it 'actSum').
4. We calculate the expected sum of the first n^2 natural numbers using the formula:
    expSum = (n^2 * (n^2 + 1)) / 2, where n is the size of the grid.
5. The missing number (let's call it 'b') can be found using the formula:
    b = expSum + (a - actSum)
6. Finally, we return the repeated number 'a' and the missing number 'b'.
Time Complexity: O(n^2), where n is the size of the grid, since we need to iterate through all the elements in the grid once.   

*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;
        unordered_set<int> st;
        int a, b;
        int actSum = 0;
        int expSum = ((grid.size()*grid.size())*((grid.size()*grid.size()) + 1)) / 2;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid.size() ; j++){
                if(st.find(grid[i][j]) != st.end()){
                    a = grid[i][j];
                }
                st.insert(grid[i][j]);
                actSum = actSum + grid[i][j];
            }
        }
        b = (int)expSum + (a - actSum);
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 2}, {2, 4}};
    vector<int> result = sol.findMissingAndRepeatedValues(grid);
    cout << "Repeated Value: " << result[0] << endl; // Output: 2
    cout << "Missing Value: " << result[1] << endl; // Output: 3
    return 0;
}