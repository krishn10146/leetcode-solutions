class Solution {
public:
    int diagonalSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int sum = 0;
        for(int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if(i == j){                 // calculates primary diagonal
                    sum += matrix[i][j]; 
                }else if(j == row -1-i){    // calculates secondary diagonal
                    sum += matrix[i][j];
                }
            }
        }
        return sum;
    }
};