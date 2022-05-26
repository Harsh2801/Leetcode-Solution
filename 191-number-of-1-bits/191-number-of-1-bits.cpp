class Solution {
public:
    int hammingWeight(uint32_t n) {
       int cnt=0;
     // long mask = (1l<<31);
     //    while(mask)
     //    {
     //        if(mask&n) cnt++;
     //        mask>>=1;
     //    }
     //    return cnt;
        
        //other way
        while(n)
        {
            n=(n&(n-1));
            cnt++;
        }
        return cnt;
    }
};