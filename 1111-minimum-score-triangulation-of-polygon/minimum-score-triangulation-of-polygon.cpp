class Solution {
public:
int solve(vector<int>&v, int start, int end,vector<vector<int>>&dp){
    if(start + 1 == end){
        return 0;
    }
    if(start + 2 ==end){
        return v[start] * v[start+1] * v[end];
    }
    if(dp[start][end]!= -1){
        return dp[start][end];
    }
    int ans = INT_MAX;
    for(int i=start+1; i<end; i++){
        ans = min(ans, v[start] * v[i] * v[end]+ solve(v,start,i,dp) + solve(v,i,end,dp));
    }
    dp[start][end] = ans;
    return dp[start][end];

}
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size(), vector<int>(values.size(),-1));
        return solve(values, 0 , values.size() -1 ,dp);
    }
};