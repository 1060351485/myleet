//
//  121 Best Time to Buy and Sell Stocks.cpp
//  
//
//  Created by Apple on 15/7/23.
//
//

class Solution {
public:
    
    // O(2n)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        
        int *minPrs = new int[n];
        int *maxPrs = new int[n];
        minPrs[0] = prices[0];  // minPrs[i] is min from index 0 to i
        maxPrs[n-1] = prices[n-1]; // maxPrs[i] is max from index i to n-1
        
        // all we need is the min buy in time and max sell time,
        // and buy in time <= sell time
        // all n prices is divided by index i,
        // find min value in prices[0] to prices[i-1]
        // and max value in prices[i] to prices[n-1]
        for( int i = 1; i < n ; i++){
            minPrs[i] = min(minPrs[i-1], prices[i]);
            maxPrs[n-i-1] = max(maxPrs[n-i], prices[n-i-1]);
        }
        int rslt = INT32_MIN;
        for(int i = 0; i < n ;i++)
            rslt = max(maxPrs[i] - minPrs[i], rslt);
        
        return rslt;
    }
    
    
    // simplify, O(1*n)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        
        int minPrs = prices[0];
        int rslt = 0;
        for( int i = 1; i < n ; i++){
            minPrs = min(minPrs, prices[i]);
            rslt = max(rslt, prices[i] - minPrs);
        }
        
        return rslt;
    }
};