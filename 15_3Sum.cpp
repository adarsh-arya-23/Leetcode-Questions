#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = -1;
        vector<vector<int>> answer;
        if(nums[0] > 0){
            return answer;
        }
        if(nums.size() < 3){
            return answer;
        }
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                sum = nums[i] + nums[j] + nums[k];
                if(sum > 0){
                    k--;
                }
                else if(sum < 0){
                    j++;
                }
                else{
                    answer.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]){
                        j++;
                    } 
                    while (j < k && nums[k] == nums[k - 1]){
                        k--;
                    } 
                    j++;
                    k--;
                }
            }
        }
        return answer;
    }
};

int main(){
    Solution s;
    vector<int> v;
    v = {1,35,2,1,6,1,-55};
    s.threeSum(v);
}

/*

Fix the first number and than use two pointer approch to find next two number 
num[i] = -(num[j] + num[k])

*/