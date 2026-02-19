/*

Approach used: Binary Search
Time Complexity: O(log n)
Space Complexity: O(1) 
Procedure:
1. We will use two binary search to find the starting and ending index of the target element in the sorted array.
2. In the first binary search, we will check if the target element is less than or equal to the middle element. If it is, we will move the high pointer to mid-1 and if it is equal, we will update the starting index.
3. In the second binary search, we will check if the target element is greater than or equal to the middle element. If it is, we will move the low pointer to mid+1 and if it is equal, we will update the ending index.

*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int start = -1;
        int low = 0 ; 
        int high = size-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(target > nums[mid]){
                low = mid+1;
            }
            else if(target <= nums[mid]){
                high = mid-1;
                if(target == nums[mid]){
                    start = mid;
                }
            }
        }
        low = 0 ; 
        high = size-1;
        int end = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(target >= nums[mid]){
                low = mid+1;
                if(target == nums[mid]){
                    end = mid;
                }
            }
            else if(target < nums[mid]){
                high = mid-1;
            }
        }
        vector<int> res;
        res.push_back(start);
        res.push_back(end);
        return res;
    }
};
int main(){
    Solution s;
    vector<int> v = {5,7,7,8,8,10};
    int target = 8;
    vector<int> res = s.searchRange(v,target);
    cout<<"Start: "<<res[0]<<" End: "<<res[1]<<endl;
}