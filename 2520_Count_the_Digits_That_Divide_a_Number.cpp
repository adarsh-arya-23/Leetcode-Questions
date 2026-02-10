#include<iostream>
using namespace std;
class Solution {
public:
    int countDigits(int num) {
        int m = num;
        long long counter = 0;
        while(m != 0){
            int d = m % 10;
            if(num % d == 0){
                counter++;
            }
            m = m / 10;
        }
        return counter;
    }
};
int main(){
    Solution s;
    cout<<"Answer: "<<s.countDigits(654)<<endl;
}


/*
Brute Force Approach:

1. Create a copy of the original number, because the number will be modified while extracting its digits.
2. Iterate through each digit of the number.
3. For every digit obtained, check whether:
   - The digit is not zero, and
   - The original number is divisible by that digit.
4. Count or process the digits that satisfy the condition.
*/
