class Solution {
public:
    int maxProfit(vector<int>&nums) {
     int n = nums.size();
     int mp = 0,bb = nums[0]; // mp = maxprofit, bb = bestbuy  

     for(int i = 1; i<n; i++){
        if(nums[i] > bb){ // go to each iteration and check if it is greater than the bb and if it is then er update mp with the max of mp, nums[i] - bb.
                                            //nums[i] - bb this is the profit made on the day of that iteration [i]
             mp = max(mp, nums[i] - bb);
        }
        bb = min (bb,nums[i]); // uodating bb to the lowest of the two so that profit can be max
     }   
     return mp;
    }
};