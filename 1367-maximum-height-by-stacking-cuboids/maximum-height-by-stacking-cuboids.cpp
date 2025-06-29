class Solution {
public:

    int solve(vector<vector<int>>& cuboids, int prev, int idx ,vector<vector<int>>&dp){
        if(idx == cuboids.size()){
            return 0;
        }
        if (dp[prev+1][idx]!= -1){
            return dp[prev+1][idx];
        }
        
        int skip_idx = solve(cuboids,prev,idx+1,dp);

        int select = 0;

        if(prev ==-1 || cuboids[prev][0] <= cuboids[idx][0] && cuboids[prev][1] <= cuboids[idx][1] && cuboids[prev][2] <= cuboids[idx][2]){
            select = cuboids[idx][2] + solve(cuboids,idx,idx+1,dp) ;
        }
         dp[prev+1][idx] = max(skip_idx, select);
         return dp[prev+1][idx];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        int ans = 0;
        // vector<vector<int>> dp(n, vector<int> (n,-1));
        for(int i=0; i<n; i++){
            sort(cuboids[i].begin(), cuboids[i].end());
        }
        sort(cuboids.begin(), cuboids.end());

        // int ans = solve(cuboids, -1, 0,dp);

        vector<int> dp(n,0);

        for(int i=0; i<n; i++){
            dp[i] = cuboids[i][2];
            for(int j=0; j<i; j++){
                if(cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2]){
                    dp[i]  =max(dp[i] , dp[j]+ cuboids[i][2] );
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};