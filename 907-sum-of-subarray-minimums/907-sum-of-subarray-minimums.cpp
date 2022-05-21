class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        long long m = 1000000007;
        long long n= a.size();
        
        vector<long long> nse(n),psoe(n);
        stack<long long> s;
        //next smaller elements
        s.push(0);
        for(int i=1; i<n; i++)
        {
            while(!s.empty() && a[i]<a[s.top()])
            {
                nse[s.top()]=i;
                s.pop();
                
            }
            s.push(i);
        }
        while(!s.empty())
        {
         nse[s.top()]=n;
            s.pop();
        }
        
        //now for previous smaller or equal to
        s.push(n-1);
        for(int i=n-2; i>=0; i--)
        {
            while(!s.empty() && a[i]<=a[s.top()])
            {
                psoe[s.top()]=i;
                s.pop();
            }
            s.push(i);
        }
         while(!s.empty())
        {
         psoe[s.top()]=-1;
            s.pop();
        }
        
        
        
        long long ans=0;
        long long x;
        for(int i=0; i<n; i++)
        {
            
            x=(((i-psoe[i])%m * (nse[i]-i)%m)%m * a[i]%m)%m;
            ans=((ans%m)+(x%m))%m;
        }
        return ans;
        
    }
};