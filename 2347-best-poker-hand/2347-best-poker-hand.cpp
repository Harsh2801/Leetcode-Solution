class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<char,int> m ; // Stores count of same suit
        map<int,int> m2 ; // Stores count of same rank
        for(auto i:suits)
        {
            m[i]++ ;
        }
        for(auto i:ranks)
        {
            m2[i]++ ;
        }
        string ans = "High Card" ;
        for(auto i:m) // Checking same suit
        {
            if(i.second == 5)
            {
                ans = "Flush" ;
				break ;
            }
        }
        for(auto i:m2) // Checking same rank
        {
            if(i.second >= 3)
            {
                ans = "Three of a Kind" ;
                break ;
            }
            else if(i.second == 2)
            {
                ans = "Pair" ;
				break ;
            }
        }
        return ans ;
    }
};