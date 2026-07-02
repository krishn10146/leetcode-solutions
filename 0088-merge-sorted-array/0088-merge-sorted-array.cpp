class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) { // we start to pick elmnts from the back to avoid formation of extra output arr. this approach uses O(1) SC
        int idx = m+n-1, i = m-1, j = n-1;

        while(i >= 0 && j >= 0){ //runs for each iteration of both arr
            if(A[i]>B [j]){ //comparing both elements and putting the larger one in the back of the final output 
                A[idx--] = A[i--];
            }else{
                A[idx--] = B[j--];
            }
        }
        while(j >= 0){ // if arr B still have elements after the above loop we just paste them in the remaining position of arr A
            A[idx--] = B[j--];
        }
    }
};