class Solution {
public:
   void helper(TreeNode* root){
        if(root==NULL){
            return;
        }
        arr.push_back(root->val);
      
        helper(root->left);
         helper(root->right);
    }
        
  vector<int>arr;
    int kthSmallest(TreeNode* root, int k) {
        helper(root);
        sort(arr.begin(),arr.end());
        return arr[k-1];
        
    }
   
    };
