class Solution {
public:
    bool searchinrow(vector<vector<int>>& mat, int target, int row){
        int n = mat[0].size();
        int str = 0, end = n - 1;

        while(str <= end){
            int mid = str + (end - str)/2;

            if(target == mat[row][mid]){
                return true;
            }else if(target > mat[row][mid]){
                str = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        int strR = 0, endR = m-1;
        while(strR <= endR){
            int midR = strR + (endR - strR)/2;

            if(target >= mat[midR][0] && target <= mat[midR][n-1]){      // found the wanted row
                return searchinrow(mat, target, midR);
            }else if(target > mat[midR][0]){        // going upward 
                strR = midR + 1;
            } else{
                endR = midR - 1;                    // going downward
            }
        }
        return false;
    }
};