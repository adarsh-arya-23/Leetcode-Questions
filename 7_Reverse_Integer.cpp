/*

Approach Used:Brute Force
Time Complexity: O(n)
Space Complexity: O(1)

Procedure:
    -> We will initialize a variable rev to store the reversed number and set it to 0.
    -> We will use a while loop to iterate through the digits of the input number x until x becomes 0.
    -> Inside the loop, we will extract the last digit of x using the modulus operator and store it in a variable digit.
    -> We will then update rev by multiplying it by 10 and adding the extracted digit to it.
    -> We will also update x by dividing it by 10 to remove the last digit.
    -> After the loop, we will check if rev is within the range of a 32-bit signed integer. If it is not, we will return 0.
    -> Finally, we will return rev as an integer.

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x /= 10;
        }

        if (rev > 2147483647 || rev < -2147483648)
            return 0;
        return (int)rev;
    }
};
int main(){
    Solution s;
    int x = 123;
    int result = s.reverse(x);
    cout<<result;
}