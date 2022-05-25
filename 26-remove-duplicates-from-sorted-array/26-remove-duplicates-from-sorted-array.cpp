class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //here count will represent unique numbers
        int count = 0;
        
        for(int i=1; i<nums.size(); i++){

            //if current num is equal to previous one, we will increase the count
            if(nums[i]==nums[i-1]) count++; 
            
            //if number is not equal, we will place the element at current index, on the position i-count, which will be the next position to last unique number, i.e. count
            else nums[i-count] = nums[i]; 
            
        }//end of loop
        
        //return the size of array which is formed with unique numbers only
        return nums.size()-count;
    }
};