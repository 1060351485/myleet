//
//  120 Triangle.cpp
//  
//
//  Created by Apple on 15/7/22.
//
//

// this 2 slow method are top to bottom
// bottom to top is faster
//   2  3
//   | \| \
//   3  2  4
//

// 12ms slow, O(n^2) space
// memo[i][j] = triangle[i][j] + min(memo[i-1][j], memo[i-1][j-1]);


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        
        if(!m) return 0;
        int n = (triangle[0]).size();
        if(!n) return 0;
        
        int **memo;
        memo = new int*[m];
        for(int i = 0;i < m;i++)
            memo[i] = new int[triangle[i].size()];
        memo[0][0] = triangle[0][0];
        int minPath = memo[0][0];
        
        for( int i = 1; i < m; i++){
            minPath = INT32_MAX;
            for(int j = 0 ; j < triangle[i].size();j++){
                if(j == 0)
                    memo[i][0] = triangle[i][0] + memo[i-1][0];
                else if(j == triangle[i].size()-1)
                    memo[i][j] = triangle[i][j] + memo[i-1][j-1];
                else
                    memo[i][j] = triangle[i][j] + min(memo[i-1][j], memo[i-1][j-1]);
                
                if(i == m-1){
                    if(memo[i][j] < minPath)
                        minPath = memo[i][j];
                }
            }
        }
        return minPath;
    }
    
    
    // 12ms, O(n) space
    class Solution {
    public:
        #include <math.h>
        int minimumTotal(vector<vector<int>>& triangle) {
            
            int m = triangle.size();
            
            if(!m) return 0;
            int n = (triangle[0]).size();
            if(!n) return 0;
            
            int **memo;
            memo = new int*[m];
            for(int i = 0;i < 2;i++)
                memo[i] = new int[triangle[m-1].size()];
            memo[0][0] = triangle[0][0];
            int minPath = memo[0][0];
            
            for( int i = 1; i < m; i++){
                minPath = INT32_MAX;
                for(int j = 0 ; j < triangle[i].size();j++){
                    if(j == 0)
                        memo[i%2][0] = triangle[i][0] + memo[i%2+(int)pow(-1,i)][0];
                    else if(j == triangle[i].size()-1)
                        memo[i%2][j] = triangle[i][j] + memo[i%2+(int)pow(-1,i)][j-1];
                    else
                        memo[i%2][j] = triangle[i][j] + min(memo[i%2+(int)pow(-1,i)][j], memo[i%2+(int)pow(-1,i)][j-1]);
                    if(i == m-1){
                        if(memo[i%2][j] < minPath)
                            minPath = memo[i%2][j];
                    }
                }
            }
            return minPath;
        }
    };
};