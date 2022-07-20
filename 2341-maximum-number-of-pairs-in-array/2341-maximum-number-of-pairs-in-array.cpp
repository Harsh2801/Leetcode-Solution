class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        //store the result
        vector<int>ans;
        int n=nums.size();
        
        unordered_map<int,int>m;
        
        //store frequency of each element occur in nums
        for(auto it:nums)
            m[it]++;
        
        int sum=0;
        
        //adding the total no. of pairs in sum 
        for(auto it:m)
        {
            sum+=it.second/2;
        }
        //add in result as total no. of pairs
        ans.push_back(sum);
        
        //add in the result as total no. of left element after pairing
        ans.push_back(n-(2*sum));
        
        return ans;
    }
};