class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int ans=INT_MIN;
        int n=a.size();
        stack<int>s;
        vector<int>nse(n);
        vector<int>pse(n);
        s.push(0);
        for(int i=1;i<a.size();i++){
        while(!s.empty()&&a[i]<a[s.top()])
        {
            nse[s.top()]=i;
            s.pop();
        }
        s.push(i);
        }
        while(!s.empty())
        {
          nse[s.top()]=a.size();
            s.pop();
        }
        
        
        s.push(a.size()-1);
        for(int i=a.size()-2;i>=0;i--){
        while(!s.empty()&&a[i]<a[s.top()])
        {
            pse[s.top()]=i;
            s.pop();
        }
        s.push(i);
        }
        while(!s.empty())
        {
          pse[s.top()]=-1;
            s.pop();
        }
        
        
    for(int i=0;i<a.size();i++)
    {
        ans=max(ans,a[i]*(nse[i]-pse[i]-1));
    }
        return ans;
    }
};