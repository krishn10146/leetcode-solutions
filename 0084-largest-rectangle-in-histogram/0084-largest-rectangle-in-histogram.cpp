class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector <int> left(n,0);                                   // contains the index of the value which is the next smaller to the curr one
        vector <int> right(n,0);                                  // contains the index of the value which is the last smaller to the curr one
                                                                  // the left and right helps to calculate the width
        stack<int> s;                                             // stores the indexes temporarily for left and right

        for(int i = n-1; i >= 0; i--){                            // calcuate the next smaller value to the curr index
            while(s.size()>0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
        
            right[i] = s.empty()? n : s.top();
            s.push(i);
        }

        while(!s.empty()){                                        // empties the stack so that left smaller can be found out
            s.pop();
        }

        for(int i = 0; i < n; i++){                               // calcuate the next smaller value to the curr index
            while(s.size()>0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
        
            left[i] = s.empty()? -1 : s.top();
            s.push(i);
        }

        int ans = 0;                                                // stores the area of curr index rectangle
        for(int i = 0; i < n; i++){
            int width = right[i] - left[i] - 1;                     // formula to calculate the width
            int currArea = heights[i] * width;                      // rectangle area
            ans = max(ans,currArea);                                // max of both will be the final answer
        }
        return ans;
    }
};