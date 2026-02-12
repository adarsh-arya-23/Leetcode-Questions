/*

Thinking Approch:
    - First sort the array.
    - return nums[size-k]
Priority Queue
    - Min-Heap
    - Max-Heap (Default of Priority Queue)
Maps:
    - Insert vector in map.
    - Create key value pair with element and frequency.
    - Now count the value until value sums to K
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int ,int> mp;
        for(int i : nums){
            mp[i]++;
        }
        for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
            k -= it->second;
            if(k <= 0){
                return it->first;
            }
        }
    return -1;
    }
};

int main(){
    Solution s;
    vector<int> v = {1,2,3,4,4,5,6,6};
    s.findKthLargest(v, 5);
}
