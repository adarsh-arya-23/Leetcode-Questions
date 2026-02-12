#include<iostream>
#include<vector>
class Solution {
public:
    int mySqrt(int x) {
        long long i = 0;
        while(i*i <= x){
            i++;
        }
        return (int)(i-1);
    }
};
int main(){
    Solution s;
    s.mySqrt(25);
}