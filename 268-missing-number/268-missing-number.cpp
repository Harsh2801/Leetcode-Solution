class Solution {
public:
 /*   int missingNumber(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=i)
            {
              return count;  
            }
            count++;
          
           
        }
        return count;
    }*/
    
     int missingNumber(vector<int>& nums) {
        int miss_num = nums.size();
        for(int i=0; i<nums.size(); i++)
        {
            miss_num ^= i;
            miss_num ^= nums[i];
        }
        return miss_num;
    }
};

