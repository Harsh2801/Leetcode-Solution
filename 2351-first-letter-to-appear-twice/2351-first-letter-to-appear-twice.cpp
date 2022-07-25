class Solution {
public:
    char repeatedCharacter(string s) 
    {
        map<char,int> mp;              // for storing the frequency of char
        
        for(auto i: s)
        {
            // if we found that this char is already present menas it is our ans return  it
            if(mp[i]==1)
                return i;
            
            // if it ocuurs first time then increase the frequency by 1
            else if(mp[i]==0)
                mp[i]++;
        }
        
        // if we do not have any char with frequency 2 then return 0
        return 0;
    }
};