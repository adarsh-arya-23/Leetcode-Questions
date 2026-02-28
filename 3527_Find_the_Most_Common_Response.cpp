/*

Approach:
1. We will first convert each vector of responses into a set to eliminate duplicates within the same response list.
2. We will then create a map to count the frequency of each unique response across all sets.
3. Finally, we will iterate through the map to find the response with the highest frequency and return it as the most common response.  

*/

#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        vector<set<string>> responses1;
        for(int i  = 0 ; i < responses.size() ; i++){
            responses1.push_back(set<string>(responses[i].begin(), responses[i].end()));
        }
        set<string> fin;
        for(const auto& s : responses1) {
            fin.insert(s.begin(), s.end());
        }
        vector<string> fin1(fin.begin(), fin.end());
        map<string, int> mp;
        for(const auto& s : responses1) {
            for(const string& word : s) {
                mp[word]++;
            }
        }
        int max = 0;
        string ans;
        for(auto const& i : mp){
            if(i.second > max){
                max = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<vector<string>> responses = {{"yes", "no", "maybe"}, {"no", "yes"}, {"maybe", "yes"}};
    cout << sol.findCommonResponse(responses) << endl; // Output: "yes"
    return 0;
}