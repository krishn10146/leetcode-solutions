class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx= 0;

        for(int i = 0; i<n; i++){
            int count = 0;          // initialise the count to 0 
            char ch = chars[i];     // ch stores the value of each iteration so that we can later it check
            while(i < n && chars[i] == ch){     // runs the loop until the same character appears
                count++; i++;       // increases the count an increments the iteration
            }
            if(count == 1){         // if the count is 1 so it only prints the character not the count
                chars[idx++] = ch;  
            }else{                  // if count is more than 1 then prints the character and the count also 
                chars[idx++] =  ch; 
                string str = to_string(count); // convert the count to string to that it can be put into the char arr
                for(char dig : str){
                    chars[idx++] = dig;     //place the count of the character in the char arr
                }
            }
            i--;        // we decrease the iteration cause it gets incremented twice once in the for loop and in the while loop 
        }
        chars.resize(idx); // we resize the arr to the new converted one 
        return idx;   
    }
};