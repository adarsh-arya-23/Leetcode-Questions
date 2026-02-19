/*

Approach: Binary Search
Time Complexity: O(log n)
Space Complexity: O(1)
Procedure:
1. We will use two binary search to find the starting and ending index of the target element in the sorted array.
2. In the first binary search, we will check if the target element is less than or equal to the middle element. If it is, we will move the high pointer to mid-1 and if it is equal, we will update the starting index.
3. In the second binary search, we will check if the target element is greater than or equal to the middle element. If it is, we will move the low pointer to mid+1 and if it is equal, we will update the ending index.

*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0;
        int high = size-1; 
        while(low <= high){
            int mid = (low+high)/2;
            if(target == nums[mid]){
                return mid;
            }
            if (nums[low] <= nums[mid]){
                if (target >= nums[low] && target < nums[mid]){
                    high = mid - 1;
                } 
                else {
                    low = mid + 1;
                }
            } 
            else{
                if(target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<int> v = {4,5,6,7,0,1,2};
    int target = 0;
    int res = s.search(v,target);
    cout<<"Element found at index: "<<res<<endl;
}