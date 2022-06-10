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
       int global=INT_MIN;
    int solve(TreeNode* root) {
        if(root==NULL)return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        int case1=max(max(l, r)+root->val, root->val);
        int case2= max(case1, l+r+root->val);
        global=max(case2, global);
        return case1;//we return case1 here because this is the only  case which can extend the maxpath to other nodes
    }
    int maxPathSum(TreeNode* r){
        solve(r);
        return global;
    }
};