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
    bool isValidBST(TreeNode* root) {
        long prev = LONG_MIN;
        bool ans = true;
        traverse(root,prev,ans);
        return ans;
    }
    
    void traverse(TreeNode* root, long &prev, bool &ans)
    {
        if(!root) return;
        traverse(root->left, prev, ans);
        if(prev < root->val)
        {
            prev=root->val;
        }
        else
        {
            ans=false;
            return;
        }
        traverse(root->right, prev, ans);
    }
};