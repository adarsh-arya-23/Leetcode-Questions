/*

Approach 1: Hash Map
Time Complexity: O(n)
Space Complexity: O(1) (since the character set is fixed)
Procedure:
1. We will use a hash map to store the frequency of each character in the string.
2. We will iterate through the string again and check the frequency of each character in the hash map. 
3. If the frequency is 1, we will return the index of that character.

*/
#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> mp;
        for(int i : s){
            mp[i]++;
        }
        for (int i = 0 ; i < s.length() ; i++){
            if(mp[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};
int main(){
    Solution s;
    string str = "leetcode";
    int res = s.firstUniqChar(str);
    cout<<"First unique character index: "<<res<<endl;
}