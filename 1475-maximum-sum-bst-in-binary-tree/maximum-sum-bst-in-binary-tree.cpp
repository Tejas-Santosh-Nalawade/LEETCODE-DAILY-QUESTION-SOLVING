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

class Packet {
public:
    int min, max, sum;
    bool isBST;
    Packet(int min, int max, int sum, bool isBST) {
        this->min = min;
        this->max = max;
        this->sum = sum;
        this->isBST = isBST;
    }
};

class Solution {
public:
    int ans;
    Packet* rec(TreeNode* curr) {
        if (curr == nullptr) {
            return new Packet(INT_MAX, INT_MIN, 0, true);
        }

        Packet* left = rec(curr->left);
        Packet* right = rec(curr->right);

        int current_sum = curr->val + left->sum + right->sum;

        bool current_is_bst =
            (left->max < curr->val && right->min > curr->val && left->isBST &&
             right->isBST);

        if (current_is_bst) {
            ans = max(ans, current_sum);
        }

        int current_mi = min(curr->val, min(left->min, right->min));
        int current_mx = max(curr->val, max(left->max, right->max));
        return new Packet(current_mi, current_mx, current_sum, current_is_bst);
    }
    int maxSumBST(TreeNode* root) {
        ans = 0;
        rec(root);
        return ans;
    }
};