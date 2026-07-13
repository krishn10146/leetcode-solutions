class Solution {                // seive of eratosthenes algorithm
public:
    int countPrimes(int n) {
        vector<bool> isprime(n+1, true);    //create a vecotr arr which put true values to all numbers (hencce assuming every number is prime)
        
        int count = 0;                  //count of prime numbers
        for(int i = 2; i < n; i++){     //loop to work on the range
            if(isprime[i]){
                count++;                // if the no is prime the count updates 
            }
            for(int j = i * 2; j < n; j+=i  ){      // declaring every number which is a multiple of i as false (non prime)
                isprime[j] = false;
            }
        }
        return count;
    }
};