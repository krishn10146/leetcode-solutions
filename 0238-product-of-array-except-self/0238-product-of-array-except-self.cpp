class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // Initialize answer array with 1s so we can safely multiply into it
        vector<int> ans(n, 1);           
        
        // --- PASS 1: Calculate Prefix Products ---
        // prefix stores the product of all elements to the left of the current index i
        int prefix = 1;                 
        for(int i = 1; i < n; i++){
            // Accumulate product of the previous element
            prefix *= nums[i-1];        
            // Store the running product of everything before index i
            ans[i] *= prefix;           
        }

        // --- PASS 2: Calculate Suffix Products ---
        // suffix stores the product of all elements to the right of the current index i
        int suffix = 1;
        for(int i = n-2; i >= 0; i--){   
            // Accumulate product of the next element
            suffix *= nums[i+1];        
            // Combine prefix product (already in ans[i]) with the new suffix product
            ans[i] *= suffix;           
        }
        
        return ans;
    }
};
