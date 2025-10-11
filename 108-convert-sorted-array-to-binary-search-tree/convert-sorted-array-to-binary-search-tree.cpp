class Solution {
private:
    TreeNode* MakeBST(vector<int>& nums, int min, int max)
    {
        if(min>max)
            return nullptr;

        int mid = min + (max-min)/2;
        TreeNode* node = new TreeNode(nums[mid]);

        node->left = MakeBST(nums, min, mid-1);   
        node->right = MakeBST(nums, mid+1, max);  
        
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return MakeBST(nums, 0, nums.size()-1);    
    }
};