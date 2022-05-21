class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        s.push(0);
        vector<int> ans(nums.size());
        for(int i=1;i<nums.size();i++){
            while(!s.empty() && nums[s.top()] < nums[i]){
                ans[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        if(!s.empty()){
            for(int i=0;i<nums.size();i++){
                while(!s.empty() && nums[s.top()] < nums[i]){
                    ans[s.top()] = nums[i];
                    s.pop();
                }
            }
        }
        while(!s.empty()){
            ans[s.top()] = -1;
            s.pop();
        }
        return ans;
}
};