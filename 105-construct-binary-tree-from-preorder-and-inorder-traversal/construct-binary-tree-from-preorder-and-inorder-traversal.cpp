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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> rec;
        for (int i = 0; i < inorder.size(); i++) {
            rec[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, rec);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int preStart, int preEnd,
                     int inStart, int inEnd,
                     unordered_map<int, int>& rec) {
        if (preStart > preEnd || inStart > inEnd) return nullptr;

        int val = preorder[preStart];
        TreeNode* root = new TreeNode(val);
        int idx = rec[val];
        int leftSubtreeSize = idx - inStart;

        root->left = helper(preorder, inorder,
                             preStart + 1, preStart + leftSubtreeSize,
                             inStart, idx - 1,
                             rec);

        root->right = helper(preorder, inorder,
                              preStart + leftSubtreeSize + 1, preEnd,
                              idx + 1, inEnd,
                              rec);

        return root;
    }
};