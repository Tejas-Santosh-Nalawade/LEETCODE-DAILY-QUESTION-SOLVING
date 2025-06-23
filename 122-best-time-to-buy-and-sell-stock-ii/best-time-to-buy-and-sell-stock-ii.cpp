class Solution {
public:
int rec(int i , vector<int> &prices, int buyStatus, int n , vector<vector<int>> &dp){
    if(i == n){
        return 0;
    }
    // check if this subProblem is already Calculated

    if(dp[i][buyStatus] !=-1){
        return dp[i][buyStatus];
    }

    int ans =0;

    if(buyStatus == 0){
        int buy = -prices[i] + rec(i+1, prices, 1, n ,dp);
        int notBuy = rec(i+1 , prices, 0, n ,dp);

        ans = max(buy, notBuy);
    }

    else{
        int sell = prices[i] + rec(i+1, prices, 0, n ,dp);
        int notSell = rec(i+1, prices, 1 ,n ,dp);

        ans = max(sell, notSell);
    }

    dp[i][buyStatus] = ans;
    return ans;

}
    int maxProfit(vector<int>& prices) {

        int n =prices.size();

        vector<vector<int>>dp(n,vector<int>(2,-1));

        return rec(0 ,prices, 0, n , dp);
    }
};