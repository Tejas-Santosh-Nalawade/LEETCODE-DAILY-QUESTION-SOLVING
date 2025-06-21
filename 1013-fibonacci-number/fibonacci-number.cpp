class Solution {
public:
    int fib(int n){
        if(n<=1) return n;
        vector<int> dp(n+1);

        dp[0] = 0;
        dp[1] = 1;
        for(int idx=2; idx<=n; idx++){
            dp[idx] =dp[idx-1] + dp[idx-2];
        }
        return dp[n];
    }
};