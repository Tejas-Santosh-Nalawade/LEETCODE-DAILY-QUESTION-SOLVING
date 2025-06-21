class Solution {
public:
    int fib(int n, vector<int> & dp) {
        if(n<=1) return n;
        if(dp[n]!= -1) return dp[n];
        int s1 = fib(n-1, dp);
        int s2 = fib(n-2,dp);

        return dp[n]=s1+s2;
    }

    int fib(int n){
        vector<int> dp(n+1, -1);
        return fib(n,dp);
    }
};