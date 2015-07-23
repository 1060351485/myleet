//
//  121 Best Time to Buy and Sell Stocks.cpp
//  
//
//  Created by Apple on 15/7/23.
//
//

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        
        int *minPrs = new int[n];
        int *maxPrs = new int[n];
        minPrs[0] = prices[0];
        maxPrs[n-1] = prices[n-1];
        
        for( int i = 1; i < n ; i++){
            minPrs[i] = min(minPrs[i-1], prices[i]);
            maxPrs[n-i-1] = max(maxPrs[n-i], prices[n-i-1]);
        }
        int rslt = INT32_MIN;
        for(int i = 0; i < n ;i++)
            rslt = max(maxPrs[i] - minPrs[i], rslt);
        
        return rslt;
    }
};