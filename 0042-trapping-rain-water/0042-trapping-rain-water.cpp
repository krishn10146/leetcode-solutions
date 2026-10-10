class Solution {
public:
    int trap(vector<int>& height) {

        // //prefix array approach
        // int n = height.size();                            
        // vector<int> lmax(n,0);                              //stores all the max value on the left of the index
        // vector<int> rmax(n,0);                              //stores all the max value on the right of the index

        // //initialising the lmax and rmax
        // lmax[0] = height[0];
        // rmax[n-1] = height[n-1];

        // for(int i = 0 ; i < n; i++){
        //     lmax[i] = max(lmax[i-1],height[i]);             // calculating the leftmax value of i
        // }
        
        // for(int i = n-1 ; i >= 0; i--){
        //     rmax[i] = max(rmax[i+1],height[i]);             // calculating the leftmax value of i
        // }        
        
        // int ans = 0;                                        // ans is the max amount of water trapped
        // for(int i = 0; i < n; i++){
        //     ans = min(lmax[i],rmax[i])-1;                   // calculating the max amount of water to be stored
        // }

        //two pointer approach
        int ans = 0;
        int n = height.size();
        int lb = 0, rb = n-1;                       // the two pointer boundaries
        int lmax = 0,rmax = 0;                      // max from traversing left and right

        while(lb<rb){                           
            lmax = max(lmax,height[lb]);            // calculating max for each in the left
            rmax = max(rmax,height[rb]);            // calculationg max for each in the right

            if(lmax<rmax){                          // if lmax is the deciding factor 
                ans += lmax-height[lb];
                lb++;
            }else{                                  // if rmax is the deciding factor
                ans += rmax-height[rb];
                rb--;
            }
        }
        return ans;
    }
};