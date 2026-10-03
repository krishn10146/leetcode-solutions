class MinStack {
public:
    stack<long long int> s;                                     // as in the formula values get multiplied so we long long int to avoid overflow condition
    long long int minval;                                       // similar to top 

    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){                                      // when the stack is empty
            s.push(val);                                    // push the val to stack     
            minval = val;                                   // and as this is the only val it will become the minimum
        }else{
            if(val < minval){                                   // if the val is less than the existing minval
                s.push((long long)2*val-minval);                // {MODIFIED VAL} we push [2*val-minval] this is the val which contain the elements of both the previous minval and the current min val 
            // we do this because when we pop the top value which is minimum, the minimum value should get updated and without doing the above process we do not have any link to the previous minval so by modifying the value we retain the reference of the previous minval
                minval = val;                                   // the new val becomes the minval
            }else{
                s.push(val);                                     //if the val is greater than the minval then we just simply push it in stack
            }
        }
        
    }
    
    void pop() {
        if(s.top() < minval){                               // if the top is the MODIFIED VAL
            minval = 2*minval-s.top();                      // this formula changes the minval to its previous value
        }
        s.pop();                                            // then the value is popped
        
    }
    
    int top() {
        if(s.top() < minval){                               // if top is the MODIFIED VAL then the actual top value is the minvalue of the stack
            return minval;
        }else{
            return s.top();                                 // the normal value of the top is returned
        }
    }
    
    int getMin() {
        return minval;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */