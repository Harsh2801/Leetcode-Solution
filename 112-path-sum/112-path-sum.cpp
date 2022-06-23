class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return NULL;
        else if(root->left==NULL && root->right==NULL)
        {
            if(targetSum-root->val==0) return true;
            else return false;
        }
        if(hasPathSum(root->left, targetSum-root->val))
        {
            return true;
        }
        if(hasPathSum(root->right, targetSum-root->val))
        {
            return true;
        }
        return  false;
    }
};