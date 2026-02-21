/*

Approach:
1. Initialize a variable `x` to store the score of the string and set it to 0.
2. Get the length of the string `s` and store it in variable `l`.
3. Iterate through the string from index 0 to `l - 2` (inclusive):
   a. For each character at index `i`, calculate the absolute difference between the ASCII values of the current character `s[i]` and the next character `s[i + 1]`.
   b. Add this absolute difference to the variable `x`. 
4. After the loop, return the value of `x` as the score of the string.  
Time Complexity: O(n), where n is the length of the string `s`, because we need to iterate through the string once to calculate the score.  

*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int scoreOfString(string s) {
    int x = 0; 
    int l = s.length(); 

    for(int i = 0; i < l - 1; i++) {
        x += abs(s[i] - s[i + 1]); 
    }
        return x;
    }
};
int main() {
    Solution sol;
    string s = "abc";
    cout << sol.scoreOfString(s) << endl; // Output: 2
    return 0;
}