class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{'|| s[i] == '['){   //checking if the i = is an opening parenthesis
                st.push(s[i]);
            }else{                                          // if i is a closing parenthesis                
                if(st.size() == 0){                         // if the stack is empty but not all the parenthesis are covered then it means that there are more closing brackets than the opening
                    return false;
                }

                if((st.top() == '(' && s[i] == ')') ||      //checking that if the closing parenthesis matches the top value of stack
                    (st.top() == '{' && s[i] == '}') ||
                    (st.top() == '[' && s[i] == ']')){
                        st.pop();
                    }else{
                        return false;                       //if the closing parenthesis is not the same as the top then it is not the valid    parenthesis    
                    }
            }
        }
        return st.size() == 0;
    }
};