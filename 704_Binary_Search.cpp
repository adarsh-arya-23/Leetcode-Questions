/*

Approach: Binary Search
1. Initialize two pointers, low and high, to the start and end of the array, respectively.
2. While low is less than or equal to high:
   a. Calculate the mid index as (low + high) / 2.
   b. If the target is greater than the element at mid, move the low pointer to mid + 1.
   c. If the target is less than the element at mid, move the high pointer to mid - 1.
   d. If the target is equal to the element at mid, return mid as the index of the target. 
3. If the target is not found after the loop, return -1 to indicate that the target is not present in the array.    

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
            if(target > nums[mid]){
                low = mid+1;
            }
            else if(target < nums[mid]){
                high = mid-1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};
int main(){
    Solution s;
    vector<int> v = {-1,0,3,5,9,12};
    int target = 9;
    cout << s.search(v,target) << endl;
    return 0;
}
