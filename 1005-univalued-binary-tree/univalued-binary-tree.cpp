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

bool inorder(TreeNode* root, int target) {
    if (root == NULL) {
        return true;
    }
    bool leftAns = inorder(root->left, target);
    if(leftAns == false) {
        return false;
    }
    if (root->val != target) {
        return false;
    }
    bool rightAns = inorder(root->right, target);
    if (rightAns == false) {
        return false;
    }
    return true;
}


bool isUnivalTree(TreeNode* root) {
    // corner/edge case: if the tree is empty, it is considered univalued
    if (root == NULL) {
        return true;
    }
    int target = root->val;
    // check if the left and right children are NULL or have the same value as the root
    return inorder(root, target);
}

};