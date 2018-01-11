/*
You are given coins of different denominations and a total amount of money amount. 
Write a function to compute the fewest number of coins that you need to make up that 
amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mincoins(amount + 1, amount + 1);
        mincoins[0] = 0;
        
        for(int idx = 1; idx < amount + 1; ++idx){
            for(int coin : coins){
                if(coin <= idx){
                    mincoins[idx] = min(1 + mincoins[idx - coin], mincoins[idx]);
                }
            }
        }
        if(mincoins[amount] > amount){
            return -1;
        }
        return mincoins[amount];        
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mincoins(amount + 1, -1);
        mincoins[0] = 0;
        
        for(int idx = 1; idx < amount + 1; ++idx){
            for(int coin : coins){
                if(coin <= idx){
                    if(mincoins[idx - coin] != -1){
                        if(mincoins[idx] > 0){
                            mincoins[idx] = min(1 + mincoins[idx - coin], mincoins[idx]);
                        }
                        else{
                            mincoins[idx] = 1 + mincoins[idx - coin];
                        }
                    }
                }
            }
        }
        return mincoins[amount];        
    }
};