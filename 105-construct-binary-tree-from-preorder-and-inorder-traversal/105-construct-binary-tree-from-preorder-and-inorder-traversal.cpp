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
// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int size=inorder.size();
//         return buildTreeHelper(inorder,preorder,0,size-1,0,size-1);
//     }
    
    
//     TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& preorder, int inS, int inE, int preS, int preE)
//     {
//         if(inS>inE) return NULL;
        
//         int rootData=preorder[preS];
//         int rootIndex=-1;
//         for(int i=inS; i<=inE; i++)
//         {
//             if(inorder[i]==rootData)
//             {
//                 rootIndex=i;
//                 break;
//             }
//         }
//         int lPreS=preS+1;
//         int lInS=inS;
//         int lInE=rootIndex-1;
//         int rPreE=preE;
//         int rInS=rootIndex+1;
//         int rInE=inE;
//         int lPreE=lInE-lInS+lPreS;
//         int rPreS=lPreE+1;
//         TreeNode* root=new TreeNode(rootData);
//         root->left=buildTreeHelper(inorder,preorder,lInS,lInE,lPreS,lPreE);
//         root->right=buildTreeHelper(inorder,preorder,rInS,rInE,rPreS,rPreE);
//         return root;
//     }
// };

class Solution {
public:
    unordered_map<int, int>mp;
    int preIndex = 0;
    //is is the starting index of the inorder 
    //ie is the ending index of the inorder
    TreeNode*buidTreeFromPre(vector<int>& preorder, unordered_map<int, int>&mp, int is, int ie){
         if(is > ie) return NULL; // we can't build any tree in this case
        TreeNode* root = new TreeNode(preorder[preIndex++]);// make trhe first index element as root from the preorder.
        if(is  == ie) return root;
        int mid = mp[root->val];// the mid will be the preorder first index 
        root->left =  buidTreeFromPre(preorder, mp, is, mid-1);
        //recursively call for starting index to mid-1 ->they will be the left subtree
        root->right = buidTreeFromPre(preorder, mp, mid+1, ie);//recursively call for mid+1 to ending index -> this will be our right subtree
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //map inorder 
        for(int i =0; i< inorder.size() ; i++){
            mp[inorder[i]] = i;
            //map value of node corresponding to it's indexing.
        }
        return buidTreeFromPre(preorder, mp, 0, preorder.size()-1);
    }
};