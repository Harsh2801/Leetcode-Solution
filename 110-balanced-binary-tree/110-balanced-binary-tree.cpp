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
    int getheight(TreeNode* root, bool &ans)
    {
        if(!root) return false;
        int leftheight = getheight(root->left, ans);
        int rightheight = getheight(root->right, ans);
        if(abs(leftheight-rightheight)>1) ans=false;
        
        return 1+max(leftheight,rightheight);
    }
    
    
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        getheight(root, ans);
        return ans;
    }
};