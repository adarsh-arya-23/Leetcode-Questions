/*

Approach:
1. We can rotate the matrix by 90 degrees clockwise using the same approach as in the previous problem (transpose and reverse).
2. We will perform the rotation up to 4 times (0, 90, 180, and 270 degrees) and check if the rotated matrix matches the target matrix after each rotation.      
For example, for the matrix:
0 1
1 0
After 90-degree rotation, we get:
1 0
0 1
After 180-degree rotation, we get:
0 1
1 0
After 270-degree rotation, we get:
1 0
0 1

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int counter = 0;
        bool istrue = true;
        while (counter < 4) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    swap(mat[i][j], mat[j][i]);
                }
            }
            for (int i = 0; i < n; i++) {
                reverse(mat[i].begin(), mat[i].end());
            }
            if(mat == target){
                return true;
            }
            counter++;
        }
        return false;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> mat = {{0, 1}, {1, 0}};
    vector<vector<int>> target = {{1, 0}, {0, 1}};
    bool result = sol.findRotation(mat, target);
    cout << (result ? "True" : "False") << endl;
    return 0;
}