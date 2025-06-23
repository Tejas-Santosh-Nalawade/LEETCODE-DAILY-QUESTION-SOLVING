class Solution {
public:
    int rec( int i, vector<int>&nums, int n, vector<int>&dp)
    {
         if( i>=n )
         {
             return 0;
         }
         // if the sub problem is already calculated
         // then return the already stored value
         if( dp[i]!=-1)
         {
             return dp[i];
         }

         int steal = nums[i] + rec(i+2, nums, n,dp);
         int notSteal = rec(i+1, nums, n,dp);

         int ans = max( steal, notSteal);

        // calculate it and store it
         dp[i]= ans;

         return ans;
    }
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>dp( n,-1);
        return rec(0, nums,n ,dp);
    }
};