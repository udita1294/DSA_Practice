class Solution {
public:
    int f(vector<int>& coins,int index,int amount,vector<vector<int>>&dp){
        if(index == 0){
            if(amount % coins[0] == 0) return amount/coins[0];
            else{
                return 1e9;
            }
        }
        if(dp[index][amount] != -1){
            return dp[index][amount];
        }
        int notTake = 0 + f(coins,index-1,amount,dp);
        int take = 1e9;
        if(coins[index] <= amount){
            take = 1 + f(coins,index,amount-coins[index],dp);
        }
        return dp[index][amount] = min(take , notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = f(coins,n-1,amount,dp);
        if(ans >= 1e9){
            return -1;
        }
        return ans;
    }
};