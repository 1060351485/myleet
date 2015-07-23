//
//  63 Unique Path II.cpp
//  
//
//  Created by Apple on 15/7/22.
//
//

class Solution {
public:
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int *memo = new int[n];  // o(n) space
        int k;
        for(k = 0; k < n; k++){  // init first line
            if(obstacleGrid[0][k] == 0)
                memo[k] = 1;
            else
                break;
        }
        for(;k < n;k++)
            memo[k] = 0;
        
        for(int i = 1 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1)
                    memo[j] = 0;
                else
                    memo[j] += memo[j-1];
            }
        }
        return memo[n-1];
    }
};