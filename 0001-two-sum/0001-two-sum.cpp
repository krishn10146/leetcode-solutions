class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;       //create an unordered map to store the values of first and their iterations
        vector<int> ans;                // stores the ans   
        int n = nums.size();

        for(int i = 0; i < n; i++){
                int first = nums[i];            // first element of the two whose sum = target
                int second = target - first;    // can calculate the second easily 
                if(m.find(second) != m.end()){  //if the second value is found in the map then we place the iteration of first and second in the ans variable 
                    ans.push_back(i);
                    ans.push_back(m[second]);
                }
                m[first] = i;                   // if second is not found then we put the first in the unordered map so that it can be used later to find the second
        }
        return ans;
    }
};