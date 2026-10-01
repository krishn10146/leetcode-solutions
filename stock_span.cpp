#include<iostream>
#include<vector>
#include<stack>
using namespace std;

                                        // span is the the max no of days where the price of stock was greater than the last higher price
                                        so span = day of current price  -  the day of last previous higher price
                                        span = i - previous high

int main() {
      // stock prices
      vector <int> prices = {100,80,60,70,60,75,85};

      // solution
      vector<int> ans (prices.size(),0);                    // filling the ans vector with zeros
      stack<int> s;                                          // stores the value of prvious highs for the current day to calculate the span 

      for (int i = 0; i < prices.size(); i++){               // traversing the vector 
          while(s.size() > 0 && prices[s.top()] <= prices[i]){    // the inner while loop runs until the stack is empty and until the top value of the stack is not the previous high for the current price 
                s.pop();                                          // if the top is not the previous high then we pop the stack until the previous high appears on top
          }
          if(s.empty()){
              ans[i] = i + 1;                                     // if the stack is empty then the span = i+1 because there will be no previous high
          }else {  
              ans[i] = i - s.top();                               // this is the condition where previous high exists on the top of the stack so the span = i - s.top(){previous high}   
          }
          s.push();                                               // after calculating for the current day the iteration of it is pushed to the top of stack and we move to the next day
      }
      for (int val: ans){
          cout << val << "" ;
      }
      cout << endl;

      return 0;
}


// the time complexity of the program is O(n)
even thogh there is a nested loop present in it this is because each piece of data is only handled twice throughout the whole process, the time doesn't grow wildly as you add more days. It stays efficient and fast, which is why we call it O(n) time complexity.




