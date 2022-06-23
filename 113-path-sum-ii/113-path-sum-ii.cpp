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
       //backtrack
      //  v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(root, targetSum, ans,v);
        return ans;
    }
};




// // global 2d array to store result
//     vector< vector<int> > res;
    
//     // helper function 
//     void pathSum(TreeNode *root, int targetSum , vector<int> &v)
//     {
//         // if root is NULL 
//         if( !root )
//             return ;
        
//         // if we reached to leaf node and get the targetsum
//         if( !root->left && !root->right && targetSum == root->val)
//         {
//             // push the lead node
//             v.push_back(root->val);
            
//             // push the vector to result 
//             res.push_back(v);
            
//             // backtrack 
//             v.pop_back();
//         }
            
            
//         // push the current node value to the vector
//         v.push_back(root->val);
        
//         // recursion to the left and right child
//         pathSum(root->left, targetSum - root->val , v);
//         pathSum(root->right, targetSum - root->val, v);
        
//         // backtrack 
//         v.pop_back();
//     }
