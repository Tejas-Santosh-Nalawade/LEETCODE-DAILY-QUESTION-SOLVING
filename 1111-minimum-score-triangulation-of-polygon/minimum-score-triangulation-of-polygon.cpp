	class Solution {
public:
    // int solve(vector<int> &v, int start, int end, vector<vector<int>> &dp) {
    //     if(start+1 == end) {
    //         return 0;
    //     }
    //     if(start+2 == end) {
    //         return v[start]*v[start+1]*v[end];
    //     }
    //     if(dp[start][end] != -1) {
    //         return dp[start][end];
    //     }
    //     int ans = INT_MAX;
    //     for(int i=start+1; i<end; i++) {
    //         ans = min(ans, v[start]*v[i]*v[end] + solve(v, start, i, dp) + solve(v, i, end, dp));
    //     }
    //     dp[start][end] = ans;
    //     return dp[start][end];
    // }
 
    int solveIter(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
 
        for(int len=3; len<=n; len++) {
            for(int i=0; i+len-1<n; i++) {
                int ans = INT_MAX;
 
                for(int k=i+1; k<i+len-1; k++) {
                    ans = min(ans, values[i]*values[k]*values[i+len-1] + dp[i][k] + dp[k][i+len-1]);
                }
 
                dp[i][i+len-1] = ans;
            }
        }
 
        return dp[0][n-1];
    }
    int minScoreTriangulation(vector<int>& values) {
        // vector<vector<int>> dp(values.size(), vector<int>(values.size(), -1));
        // return solve(values, 0, values.size()-1, dp);
        return solveIter(values);
    }
};