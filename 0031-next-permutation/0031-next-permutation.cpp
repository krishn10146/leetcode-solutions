class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int pivot = -1, n = A.size();
         for(int i = n-2; i >= 0; i--){ // pivot is the element which smaller then the just next element of it while traveling the array backwards
            if(A[i]<A[i+1]){           
                pivot = i;
                break;
            }
         
         }
         if(pivot == -1){ // this means that the arr is already at the final permutation so we reverse the whole arr to get at the starting permutation 
            reverse(A.begin(),A.end());
            return;
         }
                                        // the next permutation is the just next largest number that u can form with the help of pivot so we now search the arr
                                        // so now we travel backward to find the elemnt just larger then the pivot and then swap it with the pivot

         for(int i = n-1; i>pivot;i--){
            if(A[i]>A[pivot]){
            swap(A[i],A[pivot]);
            break;
            }
         }
                                        // now we reverse the arr from the pivot point after swapping done in last step
         int i = pivot+1,j = n-1;
         while(i<=j){
            swap(A[i++],A[j--]);
         }
    }
};