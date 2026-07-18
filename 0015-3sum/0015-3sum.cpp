class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());                     // sorting helps in applying the two pointer approach

        for(int i = 0; i<n; i++){                           // this loop fixes one value and then we find the other two based on that

            if(i > 0  && nums[i] == nums[i-1]) continue;    // this ensures that no two repetitive values of i is taken which causes duplicacy in the ans
                                                            // because if there i is taken again it will give the same triplet again which we have to avoid 

            int lb = i + 1, rb = n - 1;                     // lb = i + 1 so that both of them doesnt have the same value
            while(lb < rb){
                int sum = nums[i] + nums[lb] + nums[rb];    // calculating the sum using the three values
                if (sum < 0){                               // sum was smaller than the target so we update left boundary
                    lb++;
                }else if (sum > 0){                         // sum was bigger than the target so we update right boundary
                    rb--;
                }else{                                      // if the sum equals the target then put those the iteration of those in the ans vetor
                    ans.push_back({nums[i], nums[lb], nums[rb]});
                    lb++,rb--;                              // this moves the left and right boundary to find other combination of values whose sum with [i] equals the target

                    while(lb < rb  && nums[lb] == nums[lb-1]) lb++;     // this increments j if the value of j is similar to the last to reduce duplicacy
                }
            }
        }        
    return ans;
    }
};