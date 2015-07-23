//
//  64 Minimum Path Sum.cpp
//  
//
//  Created by Apple on 15/7/23.
//
//

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        if(!n) return 0;
        
        int *memo = new int[n];
        memo[0] = grid[0][0];
        for(int i = 1; i < n ;i++)
            memo[i] = memo[i-1] + grid[0][i];
        
        for(int i = 1; i < m;i++){
            memo[0] += grid[i][0];
            for(int j = 1; j < n;j++){
                memo[j] = grid[i][j] + min(memo[j], memo[j-1]);
            }
        }
        return memo[n-1];
    }
};