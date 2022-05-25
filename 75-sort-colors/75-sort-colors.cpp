class Solution {
public:
    void sortColors(vector<int>& nums) {
       int ptr1=0;
        int ptr2=nums.size()-1;
        int ptr3=0;
        while(ptr3<=ptr2){
            if(nums[ptr3]==0){
                swap(nums[ptr1],nums[ptr3]);
                ptr1++;
                ptr3++;
            }
            else if(nums[ptr3]==1){
                ptr3++;
            }
            else if(nums[ptr3]==2){
                swap(nums[ptr2],nums[ptr3]);
                ptr2--;
            }
        } 
    }
};