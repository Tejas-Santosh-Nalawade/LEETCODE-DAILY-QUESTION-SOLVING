class Solution {
public:
    bool isPalindrome(string &s, int l, int r, vector<vector<int>> &palin) {
        int st = l, end = r;
        if(palin[st][end] != -1) {
            return palin[st][end];
        }
        while(l<r) {
            if(s[l] != s[r]) {
                return palin[st][end] = false;
            }
            l++;
            r--;
        }
        return palin[st][end] = true;
    }

    int solve(string &s, int st, int end, vector<vector<int>> &dp, vector<vector<int>> &palin) {
        // cout<<st<<" <--> "<<end<<endl;
        if(st>=end) {
            return 0;
        }
        if(isPalindrome(s, st, end, palin)) {
            return 0;
        }
        if(dp[st][end] != -1) {
            return dp[st][end];
        }
        int ans = INT_MAX;
        for(int i=st; i<end; i++) {
            if(!isPalindrome(s, st, i, palin)) {
                continue;
            }
            // cout<<st<<" "<<i<<" "<<end<<endl;
            ans = min(ans, solve(s, i+1, end, dp, palin) + 1);
        }
        return dp[st][end] = ans;
    }

    int minCut(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), -1));
        vector<vector<int>> palin(s.size(), vector<int> (s.size(), -1));
        return solve(s, 0, s.size()-1, dp, palin);
    }
};