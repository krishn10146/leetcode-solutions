class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.length();
        while(s.length() > 0 && s.find(part) < n){  //s.find(substring) function return the starting iteration of the substring we waanna find
                    s.erase(s.find(part),part.length());  // s.erase(str,end[also the length of the part we wanna remove]) erases the substring in the given substring iteration
            // return s;
        }
        return s;
    }
};