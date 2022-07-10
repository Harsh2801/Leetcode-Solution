class Solution {
public:
    bool isSameAfterReversals(int num) {
        if(num==0)
            return true;
        int temp=num;
        int rev=0;
        while(temp>0){
            rev=rev*10+temp%10;
            temp/=10;
        }
        int temp2=rev;
        int rev2=0;
        while(temp2>0){
            rev2=rev2*10+temp2%10;
            temp2/=10;
        }
        return (rev2==num);
    }
};