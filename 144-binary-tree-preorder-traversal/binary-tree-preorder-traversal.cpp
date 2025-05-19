/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
static void preOrder(TreeNode* curr, vector<int>&ans)
{
    if(curr== NULL)
    {
        return;
    }
    ans.push_back(curr->val);
    preOrder(curr-> left , ans);
    preOrder(curr->right, ans );
}
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrder(root,ans);
        return ans;

    }
};