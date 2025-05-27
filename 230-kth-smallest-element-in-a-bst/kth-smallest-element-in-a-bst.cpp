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
    int ans = -1;
    // using counter variable
    void optimize(TreeNode* root, int&count, int&ans, int k)
    {
        if(root== NULL ){
            return; 
        }
        optimize(root->left, count , ans, k);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        optimize(root->right, count, ans ,k);
    }
    // using the k reduce 

    void inOrder(TreeNode* curr,int &k){
        if(curr == NULL)
        {
            return;
        }
        inOrder(curr->left,k);
        k--;
        if(k==0){
            ans = curr->val;
            return;
        }
        inOrder(curr->right, k);


    }
    int kthSmallest(TreeNode* root, int k) {
        int count= 0;
        ans =-1;
        // optimize(root, count, ans , k);
        inOrder(root, k);
        return ans;
    }
};