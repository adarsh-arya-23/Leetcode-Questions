/*

Approach:
1. We can reverse the number and check if the reversed number is equal to the original number.
2. If the reversed number is equal to the original number, then it is a palindrome, otherwise it is not a palindrome.
Time Complexity: O(log10(n)) where n is the input number. This is because we are reversing the number and the number of digits in the number is log10(n)
Space Complexity: O(1) because we are using only a constant amount of space to store the reversed number and the original number.

*/

#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        int m = x;
        unsigned int rev = 0;
        if(x < 0){
            return false;
        }
        else if(x == 0){
            return true;
        }
        else{
            int d;
            while(m != 0){
                d = m % 10;
                rev = rev * 10 + d;
                m = m / 10;
            }
            if(rev == x){
                return true;
            }
            else{
                return false;
            }
        }
    }
};
int main(){
    Solution s;
    int x = 121;
    cout << s.isPalindrome(x) << endl;
    return 0;
}