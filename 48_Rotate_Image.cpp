/*

Approach: Transpose and Reverse
1. First, we can transpose the matrix by swapping elements across the diagonal. This means that we swap matrix[i][j] with matrix[j][i] for all i and j where i < j.
2. After transposing the matrix, we can reverse each row to achieve the final rotated matrix. This is because a 90-degree clockwise rotation can be achieved by first transposing and then reversing each row.
For example, for the matrix:
1 2 3
4 5 6
7 8 9
After transposing, we get:
1 4 7
2 5 8
3 6 9
After reversing each row, we get:
7 4 1
8 5 2
9 6 3

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    sol.rotate(matrix);
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}