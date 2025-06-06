/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;

    void rec(TreeNode* curr, int low, int high) {
        if (curr == NULL) {
            return;
        }

        if (curr->val >= low && curr->val <= high) {
            sum += curr->val;
            rec(curr->left, low, high);
            rec(curr->right, low, high);
        }

        else if (curr->val < low) {
            rec(curr->right, low, high);
        } else if (curr->val > high) {
            rec(curr->left, low, high);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        if (root == NULL) {
            return 0;
        }

        rec(root, low, high);

        return sum;
    }
};