class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>ans;
       vector<vector<int>>temp;
        if(root==NULL) return ans;
        q.push(root);
        while(q.empty()!=true)
        {   vector<int>v;
            int n=q.size();
            for(int i=0;i<n;i++)
            {   
                TreeNode* t=q.front();
                q.pop();
                v.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            temp.push_back(v);
         int maxi=v[0];
         for(int i=1;i<v.size();i++)
             maxi=max(maxi,v[i]);
         ans.push_back(maxi);
        }
        return ans;
    }
};