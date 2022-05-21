class Solution {
public:
    bool isValid(string s) {
        stack < char > ch ; 
        for(auto val : s) {
            if(val == 'c'){
                if(  !ch.empty() && ch.top() == 'b' ) { 
                    ch.pop(); 
                    if( !ch.empty() && ch.top() == 'a' ) ch.pop(); 
                    else return false; 
                }
                else return false; 
            }
            else ch.push(val);
        }
        return ch.empty(); 
    }
};