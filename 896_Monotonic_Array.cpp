#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing  = true;
        bool decreasing  = true;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            if(nums[i] < nums[i+1]){
                decreasing = false;
            }
            if(nums[i] > nums[i+1]){
                increasing = false;
            }
        }
        return increasing || decreasing;
    }
};

int main(){
    Solution s;
    vector<int> v;
    v = {1,2,3,4,5,6};
    s.isMonotonic(v);
}