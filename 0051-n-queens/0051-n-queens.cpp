class Solution {
public:
    bool issafe(vector<string> &board, int row,int col, int n){

        // check if the row contains a queen or not
        for(int j = 0; j<n; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }

        // check if the column contains a queen or not
        for(int j = 0; j<n; j++){
            if(board[j][col] == 'Q'){
                return false;
            }
        }

        // for the condition of diagonal we will only check the upper diagonals as when we are on an index the places or position below it are empty

        // check if the left diagonal contains a queen or not
        for(int i = row, j = col; i>=0 && j>=0; j--,i--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }

        // check if the right diagonal contains a queen or not
        for(int i = row, j = col; i>=0 && j<n; j++,i--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }

    void nQueens(vector<string> &board, int row, int n, vector<vector<string>>& ans){
        if(row == n){                   // the base case where every queen is placed 
            ans.push_back({board});     // push the arrangement in ans
            return;
        }

        for(int j = 0; j < n; j++){         // travel each row of the board
            if(issafe(board,row,j,n)){      // function checks that the position of queen is correct or not
                board [row][j] = 'Q';       // if the position is correct then place a queen there
                nQueens(board, row + 1, n, ans);        //recursive call
                board[row][j] = '.';          // backtracking step ==> erases the previous decision so the loop can try placing the Queen in the next available column instead          
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<string> board (n, string(n,'.'));        //at the start the board is just filled with dots'.'
        vector<vector<string>> ans;                     // stores the final arrangement 

        nQueens(board, 0, n, ans);
        return ans;
    }
};