class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(128, -1);
        
        int left = 0, right = 0, ans = 0;
        while(right < s.length()){
            char curr_char = s[right];
            if(freq[curr_char] == -1){
                right++;
                freq[curr_char]++;
            } else{
                freq[s[left]]--;
                left++;
            }
            ans = max(ans, right - left);
            
        }
        return ans;
    }
};