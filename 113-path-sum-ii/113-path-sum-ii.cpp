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
    void helper(TreeNode* root, int sum, vector<vector<int>> &ans, vector<int>v){
        if(root == NULL){
            return;
        }
       // if we reached to leaf node and get the targetsum
        if(root->val == sum && root->left == NULL && root->right == NULL){
            //push leaf node
            v.push_back(root->val);
            //push in answer
            ans.push_back(v);
            //backtrack
            v.pop_back();
            //return;
        }
        //push current node
        v.push_back(root->val);
        //call recursion to the left and right child
        helper(root->left, sum-root->val, ans, v);
        helper(root->right, sum-root->val, ans, v);
 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root, targetSum, ans,v);
        return ans;
    }
};

