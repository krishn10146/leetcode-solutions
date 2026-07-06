class Solution { // sliding window approach is used
public:
    bool  isfreqsame(int freq1[], int freq2[]){
        for(int i = 0; i < 26; i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
}


    bool checkInclusion(string s1, string s2) { //every permutation of a string contains the same characters with the exact same frequency (count) for example in aab a comes 2 time and b comes 1 time so for every permutation of aab the freq of a and b will be same
    
        int freq[26] = {0};
        for  (int i = 0; i < s1.length(); i++){ // here we count the freq of each char of the permutation 
            int index = s1[i] - 'a'; //this gives the index of the char by subtracting the ASCII values 
            freq[index]++;
        }
         
        int windowsize = s1.length();
        for(int i = 0; i < s2.length(); i++){ // the main sliding window loop here we iterate through s2 and check every possible window of size of s1
            int windIdx = 0, idx = i;
            int windfreq[26] = {0}; // for each window we create the window freq and stores the count of ch inside it

            while(windIdx < windowsize && idx < s2.length()){ // boundary check of the window 
                windfreq[s2[idx] - 'a']++;
                windIdx++; idx++; //winIdx is not exactly an iteration windIdx is creating the window to search in and if the window exceeds the required value the loop stops/breaks
            }

            if(isfreqsame(freq,windfreq)){ // this compare the s1 freq arr with the window freq arr
                return true; // we return true if the freq is matched and if not then return false
            }
        }
        return false;
    }
};