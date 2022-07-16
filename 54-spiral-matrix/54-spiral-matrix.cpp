class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
     
    int T,B,L,R,dir;
    T=0;
    B=matrix.size()-1;
    L=0;
    R=matrix[0].size()-1;
    dir=0;  //0 for left ot right, 1 for top to bottom, 2 for right to left, 3 for bottom to top.
    int i;
    vector<int> ans;
    
    while(T<=B && L<=R)
    {
        if(dir==0)// print left to right
     {
            for(i=L;i<=R;i++) 
                ans.push_back(matrix[T][i]);
            T++;
        }   
        else if(dir==1)
        {
            for(i=T;i<=B;i++)
                ans.push_back(matrix[i][R]);
            R--;
        }
        else if(dir==2)
        {
            for(i=R;i>=L;i--)
                ans.push_back(matrix[B][i]);
            B--;
        }
        else if(dir==3)
        {
            for(i=B;i>=T;i--)
                ans.push_back(matrix[i][L]);
            L++;
        }
        dir=(dir+1)%4;
    }
    return ans;
}
};