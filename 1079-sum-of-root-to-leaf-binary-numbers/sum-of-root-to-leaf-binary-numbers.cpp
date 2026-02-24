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
    int sumRootToLeaf(TreeNode* root) {
        return DFS(root,0);
    }
    int DFS(TreeNode* ri, int val){
        if(ri== nullptr) return 0;
        val = val * 2 + ri->val;
        if(ri ->left == ri->right) return val;
        return DFS(ri->left, val) + DFS(ri->right, val);
    }
};