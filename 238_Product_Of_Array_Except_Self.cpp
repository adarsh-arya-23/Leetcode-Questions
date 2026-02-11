/*

Here all 3 coding solutions are correct but a/c leetcode the complexity should be O(n)
        - First Solution -> O(n^2)
        - Second Solution -> O(n^2)
        - Third Solution -> O(n)
    Logic Used:- 
        - Iterating over array two times whcih gives total complexity O(n).
        - In First iteration calculate product of each element before current index and save it at that index.  
        - In Second iteration calculate product of each element with prefix present values after current index and save it at that index.  
        - And at end return final answer vector.
*/

#include<iostream>
#include<vector>
using namespace std;

/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        for(int i = 0 ; i < n ; i++){
        int p = 1;
            for(int j = 0 ; j < i ; j++){
                p = p * nums[j];
            }
            for(int k = i+1 ; k < n ;k++){
                p = p * nums[k];
            }
            answer.push_back(p);
        }
        return answer;
    }
};


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            int prod = 1;
            for(int j = 0 ; j < n ; j++){
                if(i != j){
                    prod *= nums[j];
                }
            }
            answer.push_back(prod);
        }
        return answer;

    }
};
*/


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);
        int prefix = 1;
        int suffix = 1;
        for(int i = 0; i < n ; i++){
            answer[i] = prefix;
            prefix *= nums[i];
        }
        for(int i = n-1; i >= 0 ; i--){
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        return answer;
    }
};
int main(){
    Solution s;
    vector<int> v = {1,2,3,4,5};
    vector<int> answer;
    answer = s.productExceptSelf(v);
    for(int i = 0 ; i < v.size() ; i++){
        cout<<answer[i]<<" ";
    }
}