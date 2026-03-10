/*

Approach: Two Pointers
1. We can use two pointers, one starting at the beginning of the array (left) and the other starting at the end of the array (right).
2. We calculate the area formed by the lines at the left and right pointers, which is given by the formula: area = min(height[left], height[right]) * (right - left).
3. We keep track of the maximum area found so far.
4. We then move the pointer that points to the shorter line inward, as this is the only way to potentially find a larger area.
5. We repeat this process until the left pointer is no longer less than the right pointer.
Time Complexity: O(n), where n is the number of elements in the input array.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left  = 0;
        int right = n - 1;
        int area = 0;
        int height1 = 0;
        int width = 0;
        int maxArea = 0;
        while(left < right){
            height1 = min(height[left], height[right]);
            width = right - left;
            area = height1 * width;
            maxArea = max(maxArea, area);
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxArea;

    }
};
int main() {
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int result = sol.maxArea(height);
    cout << result << endl; // Output: 49
    return 0;
}