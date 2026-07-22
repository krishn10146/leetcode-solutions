class Solution {
public:
    // helper function
    void subsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &storesubsets){
        int n = nums.size();
            if(i ==  n){
                storesubsets.push_back({ans});
            return;
            
        }
        
        // include
        ans.push_back(nums[i]);
            subsets(nums, ans, i+1, storesubsets);

        ans.pop_back();
        //exclude
            subsets(nums, ans, i+1, storesubsets);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> storesubsets;
        vector<int> ans;
        subsets(nums, ans, 0, storesubsets);
        return storesubsets;
    }
};