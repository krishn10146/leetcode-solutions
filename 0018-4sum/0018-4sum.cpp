class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            if(i > 0  && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < n;){
            // int j = i + 1;
            // if(j >= n){
            //     continue;
            // }
            
                int lb = j + 1, rb = n - 1;                     // lb = i + 1 so that both of them doesnt have the same value
                while(lb < rb){
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[lb] + (long long)nums[rb];    // calculating the sum using the three values
                    if (sum < target){                               // sum was smaller than the target so we update left boundary
                        lb++;
                    }else if (sum > target){                         // sum was bigger than the target so we update right boundary
                        rb--;
                    }else{                                      // if the sum equals the target then put those the iteration of those in the ans vetor
                        ans.push_back({nums[i], nums[j], nums[lb], nums[rb]});
                        lb++,rb--;                              // this moves the left and right boundary to find other combination of values whose sum with [i] equals the target

                        while(lb < rb  && nums[lb] == nums[lb-1]) lb++;     // this increments j if the value of j is similar to the last to reduce duplicacy
                        while(lb < rb  && nums[rb] == nums[rb+1]) rb--;
                    }
                }
            
                j++;
                while(j < n && nums[j] == nums[j-1]) j++;
            }
        }
        return ans;
    }
};