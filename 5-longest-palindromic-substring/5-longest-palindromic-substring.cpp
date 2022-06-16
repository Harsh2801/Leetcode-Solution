class Solution {
public:
    string longestPalindrome(string sInput) 
    {
        int maxL = 0, left, right;
        string res, s = "#";
        
// Add the extra # chars for even length palindromes
        for(char c: sInput)
        {
            s.push_back(c);
            s.push_back('#');
        }
        
        for(int i = 0; i < s.size(); i++)
        {
            left = right = i;

// Expand as much as possible
            while(left - 1 >= 0 and right + 1 < s.size() and s[left - 1] == s[right + 1])
            {
                left--;
                right++;
            }

// Update the maximum length, if you get so
            if((right - left + 1) > maxL) 
            {
                maxL = right - left + 1;
                res = s.substr(left, maxL);
            }
        }
        
// Remove the extra # chars to print out the result
        sInput = "";
        for(char c: res)
        {
            if(c != '#') sInput.push_back(c);
        }
        return sInput;
    }
};