class Solution {
public:
    //   int findKthLargest(vector<int>& nums, int k) {
    //     sort(nums.begin(),nums.end());
    //     int s=nums.size()-k;
    //     return nums[s];
    // }
// int findKthLargest(vector<int>& nums, int k) 
//     {
//         // Take a max heap
//         priority_queue<int> q;
//         // Insert element
//         // Element would be inserted in a manner that lagest element is at the top
//         for(int i=0;i<nums.size();i++)
//         {
//             q.push(nums[i]);
//         }
//         // Take out the element k-1 times and kth element will be the required element
//         for(int i=0;i<k-1;i++)
//         {
//             q.pop();
//         }
//         //return that element
//         return q.top();
//     }
// };
    
//     int fun(int x,vector<int>& nums,int n){
//         int count = 0;
//         for(int i=0;i<n;i++){
//             if(nums[i] <= x)
//                 count++;
//         }
//         return count;
//     }
    
//     int findKthLargest(vector<int>& nums, int k) {
//         int n = nums.size();
//         int l = INT_MAX;
//         int h = INT_MIN;
//         int largest = n-k+1;  // i've find the kth smallest element from the begining 
//         for(int i=0;i<n;i++){
//             l = min(l,nums[i]);  // minimum num
//             h = max(h,nums[i]); // maximum num
//         }
//         int ans = 0;
//         while(l<=h){
//             int m = (l+h)/2; 
//             if(fun(m,nums,n)<largest)
//                 l = m+1;
//             else{
//                 if(fun(m-1,nums,n)<largest){
//                     ans = m;
//                     break;
//                 }
//                 else
//                     h = m-1;
//             }
//         }
//         return ans;
//     }
// };
    
    int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i=0;i<nums.size();++i){
		pq.push(nums[i]);
		if(pq.size()>k) pq.pop();
	}
	return pq.top();            
}
};