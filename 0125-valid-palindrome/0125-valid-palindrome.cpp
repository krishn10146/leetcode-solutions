class Solution {
public:
    bool isAlphaNum(char ch){ // function to check if the ch is alphanumneric which does not include *&^%$#@! etc.
        if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')){
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) { // uses two pointer approach
        int n = s.length();
        int st = 0, e = n - 1;
        while(st<e){
            if(!isAlphaNum(s[st])){ // checking if the ch is aphanum
                st++; continue;}
            if(!isAlphaNum(s[e])){ // checking if the ch is aphanum
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