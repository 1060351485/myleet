//
//  122 Best Time to Buy and Sell Stock II.cpp
//  
//
//  Created by Apple on 15/8/2.
//
//

class Solution {
public:
    // if go up , max - min, if go down, start from the min one
    // like 1 4 6 7 3 1 3 4
    // sum 7-1+4-1
    int maxProfit(vector<int>& prices) {
        int tempPft = 0, sum = 0;
        int start = 0, i = 1;
        int n = prices.size();
        while(i < n){  // for corner case []
            while((prices[i-1] <= prices[i])&&(i < n))
                i++;
            sum += prices[i-1] - prices[start];
            if(i == n) return sum;
            while((prices[i-1] > prices[i])&&(i < n))
                i++;
            start = i-1;
            if(i == n) return sum;
        }
        return 0;
    }
    
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int n = prices.size();
        for( int i = 1 ; i < n ; i++ ){
            sum += prices[i]>prices[i-1]?prices[i]-prices[i-1]:0;
        }
        return sum;
    }
};