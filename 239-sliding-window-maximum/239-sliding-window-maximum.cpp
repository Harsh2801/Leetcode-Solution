/**** MAINTAIN DECREASING ORDER IN DEQUE****

remove the elements from front if they are more than k
1) check if the last from the back is smaller than the one is present in deque if yes then remove that and add num[i]
2) check { if ( i >= k-1 ) } if yes then push that element in vector , we are cecking this condition cuz if i = 0 then it should not run
3) Just remeber from where you are going to insert and remove it will help
hope this will help
if you have any doubt then feel free to ask in comments
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &num, int k) 
    {
        vector<int> ans;
        deque<int> dq;
        
        for(int i=0;i<num.size();i++)
       {
            if(!dq.empty() && dq.front() == (i-k))//to remove out of bound
            {
                dq.pop_front();
            }
            
            while(!dq.empty() && num[dq.back()] < num[i])
            {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if(i >= k-1)
            {
                ans.push_back(num[dq.front()]);
            }
        }
        return ans;

        }
};
