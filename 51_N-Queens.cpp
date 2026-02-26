/*

Approach: Backtracking
1. We will create a board of size n x n and initialize it with '.' to represent empty spaces.
2. We will use a recursive function to try placing queens row by row.
3. For each row, we will check if placing a queen in a particular column is safe by checking the column, upper left diagonal, and upper right diagonal.
4. If it is safe, we will place the queen and move to the next row.
5. If we reach the end of the board (row == n), it means we have found a valid solution, and we will add it to our answer list.
Time Complexity: O(N!), where N is the number of queens. This is because in the worst case, we are trying to place each queen in every column of the board. 
Space Complexity: O(N^2) for the board and O(N) for the recursion stack, resulting in O(N^2) overall.

*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:

    bool isSafe(vector<string> &board, int row, int col, int n){
        for(int j = 0 ;  j < n ; j++){
            if(board[row][j] == 'Q'){
               return false;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        for(int i = row, j = col ; i >= 0 && j >= 0 ; j--, i--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        for(int i = row, j = col ; i >= 0 && j < n ; i--, j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    void nQueens(vector<string> &board, vector<vector<string>> &answer, int row, int n){
        if(row == n){
            answer.push_back({board});
            return;
        }
        for(int j = 0 ; j < n ; j++){
            if(isSafe(board, row, j, n)){
                board[row][j] = 'Q';
                nQueens(board, answer, row+1, n);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>> answer;

        nQueens(board,answer, 0, n);
        return answer;
    }
};
int main(){
    int n = 4;
    Solution sol;
    vector<vector<string>> result = sol.solveNQueens(n);
    
    cout << "Solutions for " << n << "-Queens problem:" << endl;
    for (const auto& solution : result) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl; 
    }
    
    return 0;
}