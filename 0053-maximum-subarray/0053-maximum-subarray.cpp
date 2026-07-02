class Solution {
public:
    int maxSubArray(vector<int>& nums) {// kadane's algorithm
        int CurrSum = 0, MaxSum = INT_MIN;
        
        for(int val : nums){
            CurrSum += val;//adding each iteration 
            MaxSum = max(CurrSum,MaxSum);
            if(CurrSum < 0){//if the sum becomes negative
                CurrSum = 0;//updates the currsum
            }
        }
        return MaxSum;
    }
};