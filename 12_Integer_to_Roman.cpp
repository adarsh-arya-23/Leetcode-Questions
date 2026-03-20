/*

Approach:
1. We can predefine the Roman numeral representations for the thousands, hundreds, tens, and ones places.
2. We can then construct the Roman numeral string by concatenating the appropriate representations based on the input number.   
3. For example, for the number 1994:
   - The thousands place is 1, which corresponds to "M".
   - The hundreds place is 9, which corresponds to "CM".
   - The tens place is 9, which corresponds to "XC".
   - The ones place is 4, which corresponds to "IV".
   - Concatenating these gives us "MCMXCIV".

*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        std::string thousands[] = {"", "M", "MM", "MMM"};
        std::string hundreds[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        std::string tens[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        std::string ones[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return thousands[num / 1000] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    }
};
int main() {
    Solution sol;
    int num = 1994;
    cout << sol.intToRoman(num) << endl; // Output: MCMXCIV
    return 0;
}