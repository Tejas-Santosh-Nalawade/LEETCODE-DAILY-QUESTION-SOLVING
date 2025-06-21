class Solution {
public:
    int memo(int n){
        if(n<=1) return n;
        vector<int> dp(n+1);

        dp[0] = 0;
        dp[1] = 1;
        for(int idx=2; idx<=n; idx++){
            dp[idx] =dp[idx-1] + dp[idx-2];
        }
        return dp[n];
    }

    int fib(int n){
        if(n<=1) return n;

        int p2 = 0 , p1 = 1, curr = 1;

        for(int idx = 2; idx <= n; idx++){
            curr =p1 + p2;
            p2 = p1; 
            p1= curr; 
        } 

        return curr;
    }
};