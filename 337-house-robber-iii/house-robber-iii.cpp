class Solution {
public:
    int rec( TreeNode* curr, unordered_map<TreeNode*,int>&dp)
    {
         if( curr==NULL)
         {
            return 0;
         }
         if( dp[curr]!=NULL)
         {
            return dp[curr];
         }
         int take = curr->val;

         if( curr->left!=NULL)
         {
                take+= rec(curr->left->left,dp) + rec(curr->left->right,dp);
         }
         if( curr->right!=NULL)
         {
            take+= rec( curr->right->left,dp)+ rec(curr->right->right,dp);
         }

         int notTake =  rec( curr->left,dp) + rec( curr->right,dp);

         int ans = max( take, notTake);
         dp[curr]= ans;
         return ans;
    }
    int rob(TreeNode* root) 
    {
        unordered_map<TreeNode*, int>dp;
        return rec( root ,dp );
    }
};