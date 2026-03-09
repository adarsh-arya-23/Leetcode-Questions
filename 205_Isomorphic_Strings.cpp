/*

Approach:
1. We can use two hash maps to store the mapping of characters from string s to string t and vice versa.
2. We iterate through both strings simultaneously and check the following conditions:
   - If the current character from string s has already been mapped to a character in string t, we check if it matches the current character from string t. If it doesn't match, we return false.
   - If the current character from string t has already been mapped to a character in string s, we check if it matches the current character from string s. If it doesn't match, we return false.
   - If neither of the characters has been mapped yet, we create a new mapping for both characters. 
3. If we successfully iterate through both strings without any mismatches, we return true, indicating that the strings are isomorphic.  
Time Complexity: O(n), where n is the length of the input strings.

*/

#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        map<char, char> mp1;
        map<char, char> mp2;
        for (size_t i = 0; i < s.length(); ++i) {
            mp1[s[i]] = t[i];
        }
        for (size_t i = 0; i < t.length(); ++i) {
            mp2[t[i]] = s[i];
        }
        

        for (size_t i = 0; i < s.length(); ++i) {
            char char_s = s[i];
            char char_t = t[i];

            if (mp1.count(char_s)) {
                if (mp1[char_s] != char_t) return false;
            } else {
                mp1[char_s] = char_t;
            }

            if (mp2.count(char_t)) {
                if (mp2[char_t] != char_s) return false;
            } else {
                mp2[char_t] = char_s;
            }
        }
    return true;
    }
};
int main() {
    Solution sol;
    string s = "egg";
    string t = "add";
    bool result = sol.isIsomorphic(s, t);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}