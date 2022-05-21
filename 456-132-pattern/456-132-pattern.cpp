class Solution {
public:
    bool find132pattern(vector<int>& nums) {
         int i,n=nums.size(), val=-1e9;
        stack<int> st;
        for(i=n-1;i>=0;i--) {
            if(nums[i]<val) return true;
            else {
                while(st.size() && nums[i]>st.top())  {
                    val=st.top(); 
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        return false;
    }
};