/*

Approach:
1. We will create a new vector called sortedArray to store the merged and sorted elements from both input vectors nums1 and nums2.
2. We will use two pointers, i and j, to traverse through nums1 and nums2 respectively. We will compare the elements at these pointers and push the smaller one into sortedArray, then move the corresponding pointer forward.
3. After one of the vectors is fully traversed, we will push the remaining elements of the other vector into sortedArray.
4. Finally, we will calculate the median of the sortedArray. If the size of sortedArray is odd, the median is the middle element. If it is even, the median is the average of the two middle elements.
Time Complexity: O(m + n), where m and n are the sizes of nums1 and nums2 respectively, because we are traversing both arrays once.
Space Complexity: O(m + n), because we are creating a new array sortedArray that contains all the elements from nums1 and nums2.

*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sortedArray;
        int i = 0;
        int j = 0;
        double res;
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                sortedArray.push_back(nums1[i]);
                i++;
            } else {
                sortedArray.push_back(nums2[j]);
                j++;
            }
        }
        while(i < nums1.size()){
            sortedArray.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size()){
            sortedArray.push_back(nums2[j]);
            j++;
        }
        int size = sortedArray.size();
        if(size % 2 != 0){
            res = sortedArray[size / 2];
        } else {
            res = (sortedArray[size / 2 - 1] + sortedArray[size / 2]) / 2.0;
        }
        return res;
    }
};
int main(){
    Solution s;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl; // Output: 2.0
    return 0;
}