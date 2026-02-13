/*

Thinking Approch:
    Approch I:-
        - Simply used nested loops.
        - Initialize a max vriable.
        - Than checked the max diff.beteen elements iterating over each elements of arrya.
    Note: Problem Solved but gives TLE due [1 <= prices.length <= 10^5] O(n^2) and required complexity:- O(n^2) <

    Approch II:-
        - First make 3 variables: buyStock, maxProfit, CurrentProfit
        - Think it like everyday you have one option either buy the stock today if price is lower than the preice you buyed the stock before.
        - Iterate through array:
            - Update buyStock if today's price is less than buyStock.
            - Update currentProfit via subtracting buying price from currentProfit.
            - Update maxProfit if currentProfit is more than maxProfit.

*/
#include<iostream>
#include<vector>
using namespace std;

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for(int i = 0 ; i < prices.size() ; i++){
            for(int j = i+1 ; j < prices.size() ; j++){
                if(max < (prices[j] - prices[i])){
                    max = prices[j] - prices[i];
                }
            }
        }
        return max;
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyStock = prices[0];
        int currentProfit = 0;
        int maxProfit = 0;
        for(int i = 0 ; i < prices.size() ; i++){
            buyStock = min(buyStock, prices[i]);
            currentProfit = prices[i] - buyStock;
            maxProfit = max(currentProfit, maxProfit);
        }
        return maxProfit;
    }
        
};

int main(){
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    s.maxProfit(prices);
}