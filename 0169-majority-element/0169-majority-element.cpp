class Solution {
public:
    int majorityElement(vector<int>& nums) { //moor's voting algorithm
        int n = nums.size();
        int freq = 1,ans = nums[0];     //initialising first elmnt of arr as ans

        for(int i = 1; i<n; i++){
            if(freq == 0){
                ans = nums[i];      //updating ans everytime freq becomes 0
            }
            if(ans == nums[i]){     //if current no is same as previous
                freq++;
            }else{
                freq--;
            }
        }


            int count = 0;          // making a count variable to check later if there is a majority element or not
            for(int val : nums){    
                if(val == ans){
                    count++;
                }
            }
            if (count > n/2){       // this means that the maj element exists
                return ans;
            }else{
                return -1;
            }

        
        return ans;
        
    }
};