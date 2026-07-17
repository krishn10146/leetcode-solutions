class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> s;
        vector<int> ans;
        int a,b;
        int n = grid.size();
        int expsum = 0;                                     // sum if the values were normally contigous    
        int actsum = 0;                                     // sum of the altered values we have in the question
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    actsum += grid[i][j];                   // calculating actual sum
                    if(s.find(grid[i][j]) != s.end()){      //checks if the value is already present in the set hence checks for duplicacy
                        a = grid[i][j];                     
                        ans.push_back(a);                   // if it is present then we push that to the ans
                    }
                    s.insert(grid[i][j]);                   // if the value is not duplicate then we store it in the set
                }
        }
        expsum = (n*n)*(n*n + 1)/2;                         // calculating expsum
        b = expsum + a - actsum;                            // this is how to calculate b
        ans.push_back(b);                                   // b gets pushed back into the ans
        return ans;
    }
};