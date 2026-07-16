class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;     // these are the four variable which track the boundaries 
        vector<int> ans;                                        // ans will be stores in this vector

        while(srow <= erow && scol <= ecol){
        for(int i = scol;i <= ecol; i++){                       //prints the top boundary repetedly
            ans.push_back(matrix[srow][i]);
        }
        for(int i = srow + 1;i <= erow; i++){                   // prints the right boundary repetedly
            ans.push_back(matrix[i][ecol]);
        }
        for(int i = ecol - 1; i >= scol; i--){                  // prints the right bottom repetedly
            if(srow == erow){                   //ensure that no duplicay occurs
                break;
            }
            ans.push_back(matrix[erow][i]);
        }
        for(int i = erow - 1; i >= srow + 1; i--){             // prints the left boundary repetedly
            if(ecol == scol){                     //ensure that no duplicay occurs
                break;
            }
            ans.push_back(matrix[i][scol]);
        }
        srow++,scol++,erow--,ecol--;                           // updating the varibales to move on the next inward boundaries
        }
        return ans;
    }
};