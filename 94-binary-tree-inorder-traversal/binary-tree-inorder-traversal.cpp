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
static void inOrder(TreeNode* curr, vector<int>&ans)
{
    if(curr== NULL)
    {
        return;
    }
    inOrder(curr-> left , ans);
    ans.push_back(curr->val);
    inOrder(curr->right, ans );
}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inOrder(root,ans);
        return ans;

    }
};