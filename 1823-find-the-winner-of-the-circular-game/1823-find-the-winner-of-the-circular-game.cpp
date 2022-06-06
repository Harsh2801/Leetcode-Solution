class Solution {
public:
    int findTheWinner(int n, int k) {
if ( n==1) 
 return 1 ;
 int r =  (findTheWinner(n-1,k)+k)%n;
  if (r == 0)
  return n ;
  else return r;
    }
};