class Solution {
public:
    int reverse(int x) {
        int rnum = 0;

        while(x != 0){
            int digits = x % 10;
            x = x/10;
            if (rnum < INT_MIN/10 || rnum > INT_MAX/10){    //this condition checks if the value of rnum after multiplying by 10 exeeds the 32bit range or not it it does then we return 0
                return 0;
            }
            rnum = rnum*10 + digits;
        }
        return rnum;
    }
};