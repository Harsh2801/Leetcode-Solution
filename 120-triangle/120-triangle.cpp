// class Solution {
// public:
//    long long solve(vector<vector<int>> &dp, vector<vector<int>> &nums, int i, int j, int n)
// {
//     if( j>=n || j<0)
//         return INT_MAX;
//     if(i>=n)
//         return 0;
//     if(dp[i][j]!=-1)
//         return dp[i][j];
//     long long val1=nums[i][j]+solve(dp,nums,i+1,j,n);
//     long long val2=nums[i][j]+solve(dp,nums,i+1,j+1,n);
//     return dp[i][j]=min(val1,val2);
        
// }
// int minimumTotal(vector<vector<int>>& triangle) {
//     int n=triangle.size();
//     vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
//     return solve(dp,triangle,0,0,n);
// }
// };



class Solution {
    int solve(vector<vector<int>>& triangle, int i, int j,int dp[205][205]){
      
        if(i == triangle.size() ){
            return 0 ;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }   
        
        return dp[i][j] = triangle[i][j] + min(solve(triangle, i+1,j, dp), solve(triangle,i+1, j+1, dp)) ;
        
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) { 
        int n = triangle.size() ;
        int dp[205][205];
        memset(dp,-1,sizeof(dp));
        return solve(triangle, 0, 0, dp) ;
    }
};