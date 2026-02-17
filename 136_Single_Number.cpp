/*

Approach Used: 

used XOR operator 
    XOR of any number to itself is zero and with other its non zero
    just iterate over vector and do XOR and atlast remaing number will be the unique in the list.

*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            res = res^nums[i];
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> v = {4,1,2,1,2};
    if(s.singleNumber(v)){
        cout<<"The non-repeated number is: "<<s.singleNumber(v)<<endl;
    }
    else{
        cout<<"No non-repeated number is present"<<endl;
    }
}