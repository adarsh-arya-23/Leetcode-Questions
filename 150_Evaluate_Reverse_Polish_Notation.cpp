/*

// Approach:
// Use a stack to evaluate the Reverse Polish Notation expression.
// Traverse each token:
// 1. If the token is a number, convert it to integer and push onto the stack.
// 2. If the token is an operator, pop the top two elements (b then a),
//    apply the operator as (a op b), and push the result back onto the stack.
// After processing all tokens, the top of the stack contains the final result.


*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto& x:tokens){
            if(x != "+" && x != "-" && x != "*" && x != "/"){
                s.push(stoi(x));
            }
            else{
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                s.push(x=="+"?a+b:x=="-"?a-b:x=="*"?a*b:a/b);
            }
        } 
        return s.top();
    }
};


int main() {
    Solution s;
    vector<string> tokens = {"4", "13", "5", "/", "+"};
    int result = s.evalRPN(tokens);
    cout << "Result: " << result << endl;
    return 0;
}