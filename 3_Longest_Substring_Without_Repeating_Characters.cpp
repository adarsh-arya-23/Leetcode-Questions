/*

Approach: 
1. We can use a sliding window technique to solve this problem efficiently.
2. We maintain a set to keep track of the characters in the current window.
3. We use two pointers, `left` and `right`, to represent the current window. Initially, both pointers are at the beginning of the string.
4. We iterate through the string with the `right` pointer. For each character at `right`, we check if it is already in the set.
5. If it is, we remove characters from the set starting from the `left` pointer until we remove the duplicate character. We also move the `left` pointer accordingly.
6. After ensuring that the current character at `right` is not in the set, we add it to the set and update the maximum length of the substring found so far.

*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left = 0, maxLen = 0;
        for (int right = 0; right < s.size(); right++) {
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(s) << endl; // Output: 3
    return 0;
}