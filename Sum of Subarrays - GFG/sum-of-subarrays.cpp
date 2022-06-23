// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long subarraySum(long long a[], long long n)
    {
         long int result = 0,temp=0;
 long p=1000000007, sum=0;
        for(int i=0;i<n;i++)
           sum= (sum + a[i]*(n-i)*(i+1))%p;
        return sum%p;
    }
};

// { Driver Code Starts.
int main()
 {
     long long t; 
     cin>>t;
     while(t--)
     {
         long long n; cin>>n;
         long long a[n+5];
         for(long long i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.subarraySum(a, n)<<endl;
     }
    return 0;
}
  // } Driver Code Ends