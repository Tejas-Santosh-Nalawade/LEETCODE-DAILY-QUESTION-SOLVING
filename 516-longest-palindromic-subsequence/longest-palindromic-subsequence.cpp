class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1; i<=n; i++){
            dp[i][i]=1;
        }
        
        for(int l=2; l<=n; l++){
            for(int i=1; i<=n-l+1; i++){
                if(s[i-1]==s[i+l-2]){
                    dp[i][i+l-1]=2+dp[i+1][i+l-2];
                }
                else{
                    dp[i][i+l-1]=max(dp[i][i+l-2],dp[i+1][i+l-1]);
                }
            }
        }
      
        return dp[1][n];
        return 0;
    }
};