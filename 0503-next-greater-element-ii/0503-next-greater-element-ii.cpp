class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>s;
        vector<int> ans(n,0);                              
        // We traverse 2n to simulate the circular array behavior

        for(int i = 2*n-1; i >= 0; i--){                     // We use i % n to map the index back to the range [0, n-1],
                                                            // allowing us to access the original array elements correctly.
            while(s.size() > 0 && nums[s.top()] <= nums[i%n]){
               s.pop(); 
            }
            ans[i%n] = s.empty() ? -1 : nums[s.top()];
            s.push(i%n);
        }    
        return ans;
    }
};