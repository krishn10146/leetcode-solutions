class Solution {
public:

    bool isPalindrome(string s) { // uses two pointer approach
        int n = s.length();
        int st = 0, e = n - 1;
        while(st<e){
            if(!isalnum(s[st])){ // checking if the ch is aphanum  [alnum is an inbuit c++ funvtion to use this we must include <cctype>]
                st++; continue;}
            if(!isalnum(s[e])){ // checking if the ch is aphanum
                e--; continue;}
            if(tolower(s[st]) == tolower(s[e])){ // to lower converts the ch to lowecase 
                st++;
                e--;
            }else{
                return false;
            }
        }
        return true;
    }
};
