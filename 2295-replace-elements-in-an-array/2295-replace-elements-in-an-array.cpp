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