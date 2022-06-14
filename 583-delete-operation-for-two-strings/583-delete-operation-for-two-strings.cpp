class Solution {
public:
// if we find LCS (longest common subsequence) for word1 and word2 , it will be "ea" (size = 2).

// if we observe , we've removed one character from word1 ( which is size(word1) - LCS ).
// And same for word2 ( which is size(word2) - LCS ).

// Basically we are not deleting the elements which are part of LCS string.

// Because we need minmum number of steps, so we'll not delete the characters which are already same in two strings to reduce number of steps.

// So basically our final ans will be ( word1.size( ) - LCS ) + ( word2.size( ) - LCS )
// So, ans = word1.size( ) + word2.size( ) - 2 * LCS
   
    
    int minDistance(string word1, string word2) {
       int n=word1.size();
        int m= word2.size();
        int dp[n+1][m+1];
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<m+1; j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                } 
            }
        }
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
               if(word1[i-1]==word2[j-1])
               {
                   dp[i][j] = 1+dp[i-1][j-1];
               }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                
            }
            
        }
        int lcs = dp[n][m];
        return (m+n-2*lcs);
    }
};