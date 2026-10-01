class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> m;                            // stores the next greater for the elements of the nums2
        stack<int> s;

        for(int i = nums2.size()-1; i >= 0; i--){             // travel the array in reverse fashion
            while(s.size()>0 && s.top()<=nums2[i]){           // checks if the stack is empty or if the top is less than the i
                s.pop();                                      // if the top is less than i then we pop it and check the next one
            }
            if(s.empty()){
                m[nums2[i]] = -1;                             // if stack is empty then the next element do not exist for i
            }else{
                m[nums2[i]] = s.top();                        // if top is greater than the i then we store that in the map
            }                                                   
            s.push(nums2[i]);                                 // then push the i in the stack to compare for the next value
        }
        vector<int> ans;                                      // stores the ans (next greater for nums1)
        for(int i = 0; i<nums1.size(); i++){                  // travel the array in forward manner
            ans.push_back(m[nums1[i]]);                       // searches the next greater value that is already stored in the 
        }                                                     // unordered map and then push it to the ans vector
        return ans;
    }
};