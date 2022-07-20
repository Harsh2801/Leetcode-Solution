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
TreeNode* solve(vector<int>& nums,int lo, int hi)
{   
    
    
    int n=hi-lo;
    //base case
    if(n==0)
    {
        return NULL;
    }
    
    
    int mid=(hi+lo)/2;
   //root is mid element
    TreeNode *root=new TreeNode(nums[mid]);
    //mid sudhi na badha left ma
    root->left=solve(nums,lo,mid);
    //mid+1 thi badha right ma and mid valo root
    root->right=solve(nums,mid+1,hi);
    return root;
}
    
    
    public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,0,n);
    }
};