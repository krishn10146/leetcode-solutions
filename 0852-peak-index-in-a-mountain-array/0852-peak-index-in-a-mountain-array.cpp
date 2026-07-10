class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
     int str = 1, end = arr.size()-2;
     while(str<=end){
        int mid = str + (end - str)/2;
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            return mid;
        }else if(arr[mid-1]>arr[mid]){
            end = mid-1;
        }else{
            str = mid+1;
        }
        

     }   
     return -1;
    }
};