// We are using array of size 10^6 (maximum range of a[i] as per contraints).

// First of all we are storing the position of each element ( they are unique )
// After each operation we find position of first element in operation using array m and change element in a on that position with second element of operation
// store the position of new element in m



class Solution {
public:
       vector<int> arrayChange(vector<int> a, vector<vector<int>>& op) {
        int n = a.size();
        
        int m[1000007];
        for(int i = 0; i < n; i++){
            m[a[i]] = i;
        }
        for(auto i: op){
            int x = i[0], y = i[1];
            int pos = m[x];
            a[pos] = y;
            m[y] = pos;
        }
        return a;
    }
};