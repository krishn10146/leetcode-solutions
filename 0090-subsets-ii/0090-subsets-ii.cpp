class Solution {
public:
    // helper function      (using backtrackting to generate all subsets)
    void subsetsWithDup(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &storesubsets){
        int n = nums.size();
            if(i == n){                             // if (i == n) then it means that all the iterations or values are travelled
                storesubsets.push_back({ans});      // so we pushback those elements in the vector ans
            return;
            
        }
        //for every iteration we have two options of INCLUDING and EXCLUDING

        // include
        ans.push_back(nums[i]);                     // including current element to subset 
            subsetsWithDup(nums, ans, i+1, storesubsets);  // move to next step with item included

         // (backtracking) removing last element to undo choice 
        ans.pop_back();        
        int idx = i + 1;                                        
        while(idx < n && nums[idx] == nums[idx - 1]) idx++;     //if consecutive values are equal then it incremetns the index until a
                                                                // diffent is found               
        //exclude
        //excluding the current element from subset
        // move to next index without the item
            subsetsWithDup(nums, ans, idx, storesubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> storesubsets;           //  stores all the subsets in itself
        vector<int> ans;                            //  tracks the current subset configuration
        subsetsWithDup(nums, ans, 0, storesubsets);        // starting the recoursive tracking the from index 0
        return storesubsets;
    }
};