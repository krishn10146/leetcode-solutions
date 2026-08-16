class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);           // vector which stores the new product array        
        int prefix = 1;                 

        for(int i = 1; i<n; i++){
            prefix *= nums[i-1];        // calculate the prefix for each iteration of the loop 
            ans[i] *= prefix;           // this prefix gets stored in the ans vector
        }

        int suffix = 1;
        for(int i = n-2; i >=0; i--){   
            suffix *= nums[i+1];        // calculate the suffix for each iteration of the loop
            ans[i] *= suffix;           // this suffix gets stored in the ans vector (both suffix and prefix combine to make the ans of the product array)
        }
        return ans;
    }
};