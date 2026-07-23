class Solution {
public:
    void permutation(vector<int>& nums, int idx, vector<vector<int>> &ans){     //helper function
        int n = nums.size();
        if(idx == n){                           //if the function hits the base case
            ans.push_back({nums});              //push permutations in the ans vector
            return;
        }
        for(int i = idx; i<n; i++){             //The idx starts at and represents the current "space" the recursion is working on
 
            swap (nums[idx], nums[i]);          // swap the values at index to make different permutations
            permutation(nums,idx+1,ans);        // recursive call
            swap(nums[idx], nums[i]);           //backtracking (after the base case is reached then go back to prior stages to select different entry)
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;            // stores the permutations
        permutation(nums, 0, ans);
        return ans;
    }
};