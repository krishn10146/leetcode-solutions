class Solution {
public:
    int diagonalSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int sum = 0;
        for(int i = 0; i < row; i++){
            sum += matrix[i][i];        // adds element at priority diagonal with same indices (1,1) (2,2)
            if(i != row-i-1){           // this ensures that no common element is added twice in both primary and seondary diagonal
                sum += matrix[i][row-i-1];
            }
        }
        return sum;
    }
};