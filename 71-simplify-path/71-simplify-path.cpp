class Solution {
public:
    string simplifyPath(string path) {
       // we are using stack becase we have to pop out the most recent file when we see '..'
        stack<string>st;
        string ans = "";
        string temp = "";
        int n = path.length();
  // if path does not end with the '/' then we have to add it without adding it otherwise 
  // we will not able to add the last temp string because we dont find / before i will reached to n 
        if(path[n-1]!='/')
        {
            path += '/';
            n++;
        }
        int i = 1; // we will start from index 1 
        while(i<n)
        {
            if(path[i]=='/')
            {
                if(temp=="" || temp== ".")
                {
                    //ignor it
                }
                else if(temp== "..")
                {
                    if(!st.empty())
                    st.pop();
                }
                else
                {
                    st.push(temp);
                } 
             temp = "";
            }
            else
            {
                temp += path[i];
            }
            i++;
        }
        // make the canonical string through poping the stack
        while(!st.empty())
        {
            ans = '/'+st.top()+ans;
            st.pop();
        }
        // it handel the case when we dont find anything as ans 
        if(ans=="")
        {
            ans += '/';
        }
     return ans;
    }
};