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
   int sum=0;
    void preOrder(TreeNode* curr, char dir)
    {
        if(curr == NULL)
        {
            return;
        }
        if(curr->left== NULL && curr->right== NULL && dir=='l' )
        {
            // left leaf node
            sum+= curr->val;
            return;
        }
        preOrder(curr->left,'l');
        preOrder(curr->right,'r');
    }

    int sumOfLeftLeaves(TreeNode* root) {
        sum= 0;
        preOrder(root, 'c');
        return sum;

    }
};