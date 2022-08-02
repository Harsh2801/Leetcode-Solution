// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         priority_queue<int , vector<int> , greater<int>> pq;
//         for(int i = 0 ; i < matrix.size() ; ++i){
//             for(int j = 0 ; j < matrix[0].size() ; ++j){
//                 pq.push(matrix[i][j]);
//             }    
//         }
//         k = k - 1;
//         while(k--){
//             pq.pop();
//         }
//         return pq.top();
//     }
// };

class Solution {
public:
    typedef long long ll;
	
    // to get number of elements in matrix less than equal to 'target'
    int search(vector<int> &arr, ll target){
        ll low = 0, high = arr.size()-1;
        ll mid = 0;
                
        while(low <= high){
            mid = low + (high - low)/2;
			
            if(arr[mid] <= target){
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return low;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        ll low = -10e9, high = 10e9;
        ll mid = 0;
        
        int count = 0;
        while(low <= high){
            mid = low + (high - low)/2;
                                    
            count = 0;
            for(int i=0; i<matrix.size(); i++){
                count += search(matrix[i], mid);
            }                            
            
            if(count < k) low = mid + 1; //if it's less we should include larger numbers
            else high = mid - 1; //if it is greater then or equal we look towards smaller number
        }
                
        return low;
    }
};