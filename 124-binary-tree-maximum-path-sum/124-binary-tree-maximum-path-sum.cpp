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
        int lst = solve(root->left);
        int rst = solve(root->right);
        int case1=max({max(lst, rst)+root->val, root->val,lst+rst+root->val});
        global=max(case1, global);
        int pass = root->val+max(lst, rst);
        return pass>0?pass:0;//we return case1 here because this is the only  case which can extend the maxpath to other nodes
    }
    int maxPathSum(TreeNode* root){
        solve(root);
        return global;
    }
};