class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans; // stores the answer in this string

        reverse(s.begin(),s.end());  // first we reverse the whole string and then we reverse individual word 

        for(int i = 0; i < n; i++){ // time complexity is O(n) even though it uses two loops this is because both the loop increments the same iteration
            string word;         

            while(i < n && s[i] != ' '){  // ( i < n ) so that the iteration doesnt go out of the loop and s[i] != ' ' stops the loop before the space to select the word
                word += s[i];               // take out individual word and reverse it in the next step
                i++;
            }
            reverse(word.begin(),word.end());  // reverse the word string to make it an actual word
            
            if(word.length() > 0){
                ans += ' ' +  word; // add the word in the ans 
            }
        }
        return ans.substr(1);
    }
};