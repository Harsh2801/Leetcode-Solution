class Solution {
public:
    static bool comp(vector<int> &v1, vector<int> &v2){
        if(v1[0]==v2[0])
            return v1[1]<v2[1];
        
        return v1[0]>v2[0];
        
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
       
        sort(people.begin(), people.end(), comp);
        
        for (auto& v : people) 
            result.insert(result.begin() + v[1], v);
        
        return result;
    }
};