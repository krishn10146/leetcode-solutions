class Solution {
public:
    int addDigits(int num) {
        
        
       while(num >= 10 )
       {
         
        int digit = num%10;
        num  = num/10;
        num = digit + num;
        
       }
        return num;
    }
};