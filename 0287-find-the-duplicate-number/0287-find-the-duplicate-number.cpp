class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // this approach is using the unordered set the TC is O(n) but the SC is O(n)


        // unordered_set<int> s;                        
        // int n = nums.size();
        // int ans;
        // for(int i = 0; i < n; i++){
        //     if(s.find(nums[i]) != s.end()){
        //         ans = nums[i];
        //     }
        //     s.insert(nums[i]);
        // }
        // return ans;


        // we use the two pointer (slow and fast) approach whih gives TC O(n) and SC of O(1) because there is no need to make a seperate set 
        // in this approach we assume the array nums as a linked list where each index points toward the value it stores at that index
        // as a duplicate value exists there will be a cycle in there

        int slow = nums[0], fast = nums[0];     // two pointers slow and fast to travel the array

        do {
            slow = nums[slow];                  // increment slow by 1
            fast = nums[nums[fast]];            // increment fast by 2
        } while (slow != fast);                 // until they meet in a cycle i.e. there index points the same value

        slow = nums[0];                         // re initialising the slow with the first value of the array

        while(slow != fast){                    // when they both are equal they will always point to the duplicate value of the array 
            slow = nums[slow];                  // increment slow by 1
            fast = nums[fast];                  // increment fast by 1
        }
        return fast;                            // we can return either fast or slow as both are same in the end
    }
};