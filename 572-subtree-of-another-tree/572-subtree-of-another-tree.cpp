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
    bool aresame(TreeNode* root, TreeNode* subroot)
    {
        if(root==NULL && subroot==NULL)
        {
            return true;
        }
        if(root==NULL || subroot==NULL)
        {
            return false;
        }
        return (root->val==subroot->val && aresame(root->left,subroot->left) && aresame(root->right,subroot->right));
        
    }
    
    
    void traverse(TreeNode* root, TreeNode* subRoot, bool &ans)
    {
        if(aresame(root,subRoot))
        {
            ans=true;
            return;
        }
        if(!root) return;
        traverse(root->left,subRoot,ans);
        traverse(root->right, subRoot, ans);
    }
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans=false;
        traverse(root, subRoot, ans);
        return ans;
    }
};