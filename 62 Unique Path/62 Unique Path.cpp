//
//  62 Unique Path.cpp
//  
//
//  Created by Apple on 15/7/22.
//
//

class Solution {
public:
    int uniquePaths(int m, int n) {
        int *memo = new int[n];
        for(int i = 0; i < n; i++)
            memo[i] = 1;
        for(int i = 1 ; i < m; i++)
            for(int j = 1; j < n; j++)
                memo[j] += memo[j-1];
        return memo[n-1];
    }
};