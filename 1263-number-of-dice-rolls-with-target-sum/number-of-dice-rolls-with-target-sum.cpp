class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<int> dp(target+1,0);
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            vector<int> newDp(target + 1, 0);
            for (int j=target; j>=1 ; j--)
            {
                dp[j] = 0;
                for(int p=1; p <=k && j-p>=0; p++){
                    if (j - p >= 0) {
                        newDp[j] = (newDp[j] + dp[j - p]) % MOD;
                    }
    
                }
            }
            dp = newDp;
        }
        return dp[target];   
    }
};