class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        unordered_map<char, bool> seen;
        string ans;
        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {// increase frequency of characters
            freq[s[i]]++;
        }
         for(int i=0;i<s.length();i++) {
            freq[s[i]]--;                      //if we iterated frquency at that point should be minused by 1
             if(seen[s[i]]){                   //if present simply ignore and continue
               
                continue;
            }
             while(!st.empty() && s[i]<st.top() && freq[st.top()]>0){  // stack empty na thay and character is smaller than top and frequency is positive
             
                 seen[st.top()]=false;   //seen ko false karke pop
                 st.pop();
             }
             st.push(s[i]);    //otherwise push
             seen[s[i]]=true;  //seen ko true
             
         }
        
        //logic over
        //now push all element of stack to string
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        // revrse all becoz stack is LIFO
        reverse(ans.begin(),ans.end());
        return ans;
    }
};