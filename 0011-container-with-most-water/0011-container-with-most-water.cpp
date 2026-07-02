class Solution {
public:
    int maxArea(vector<int>& height) { // uses two pointer approach
        int n = height.size();
       int lb = 0; // left boundary for the water
        int rb = n-1; // right boundary for the water
        int amt = 0; 
       while(lb<rb){
        int w = rb - lb; // width of the container
        int h = min(height[lb],height[rb]); // height of the container
        amt = max(amt,w*h); // width * height
        height[lb]<height[rb]?lb++:rb--; // using ternary operator to decide which boundary to move
       }
       return amt;
    }
};