class Solution {
public:
    int solve(vector<int>& v, int start, int end, vector<vector<int>>& dp) {
        if (start > end) return 0;

        if (dp[start][end] != -1) return dp[start][end];

        int ans = 0;
        for (int i = start; i <= end; i++) {
            int coins = v[start - 1] * v[i] * v[end + 1] +
                        solve(v, start, i - 1, dp) +
                        solve(v, i + 1, end, dp);
            ans = max(ans, coins);
        }

        return dp[start][end] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n + 2, 1);  
        for (int i = 0; i < n; i++) {
            v[i + 1] = nums[i];
        }

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return solve(v, 1, n, dp); 
    }
};