class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        int str = 0, end = n-1;
        while(str <= end){
            int mid = str +(end - str)/2;
            if(mid == 0 && nums[0] != nums[1]){return nums[mid];}       // constraint to check if the first value is the single element or not
            if(mid == n-1 && nums[n-1] != nums[n-2]){return nums[mid];} // constraint to check if the last value is the single element or not
            if(nums[mid-1] != nums[mid] && nums[mid+1] != nums[mid]){
                return nums[mid];
            }
            else if(mid % 2 == 0){  // checks if the mid is even and if it is then
                if(nums[mid-1] == nums[mid]){ // checking if the previous value of mid id equal to value of mid if it is then it means that odd no of elements to the left of mid which tell us that out of those odd no of elements there will be a single element
                    end = mid -1; 
                }else{                        // if the mid is not equal to the previous one then it means that the single element is in the right part as it contain odd no of elements
                    str = mid +1;
                }
            }else{                  // checks if the middle value is odd then the no of arr elements is also odd
                if(nums[mid-1] == nums[mid]){   // checking if the previous value of mid id equal to value of mid if it is then it means that there are even no of elements to the left of mid which tell us that all of them are pairs hence the single value is not present in the left region
                    str = mid+1;
                }else{
                    end = mid-1;     // if the mid is not equal to the previous one then it means that the single element is in the left part as it contain odd no of elements
                }
            }
        }
        return 0;
    }
};