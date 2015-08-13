//
//  Set Matrix Zero.cpp
//  
//
//  Created by Apple on 15/8/13.
//
//

class Solution {
public:
    
    // slow.. 112ms
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row, col;
        for(int i = 0 ;i < m ;i++){
            for(int j = 0; j < n ; j++){
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        unique(row.begin(), row.end());
        sort(col.begin(), col.end());
        unique(col.begin(), col.end());
        
        int rn = 0, cn = 0;
        for(int i = 0; i < m; i++){
            if((rn < row.size())&&(i == row[rn])){
                for(int j = 0; j < n ;j++)
                    matrix[i][j] = 0;
                rn++;
            }
        }
        for(int j = 0; j < n; j++){
            if((cn < col.size())&&(j == col[cn])){
                for(int i = 0; i < m ;i++)
                    matrix[i][j] = 0;
                cn++;
            }
        }
    }
    
    // 92ms O(2*m*n) O(m+n) 
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row, col;
        for(int i = 0 ;i < m ;i++)  // check row and col in order, no need to sort
            for(int j = 0; j < n ; j++)
                if(matrix[i][j] == 0){
                    row.push_back(i);
                    break;
                }
        for(int j = 0 ;j < n ;j++)
            for(int i = 0; i < m ; i++)
                if(matrix[i][j] == 0){
                    col.push_back(j);
                    break;
                }
        // unique(row.begin(), row.end());
        // sort(col.begin(), col.end());
        // unique(col.begin(), col.end());
        
        int rn = 0, cn = 0;
        for(int i = 0; i < m; i++)
            if((rn < row.size())&&(i == row[rn])){
                for(int j = 0; j < n ;j++)
                    matrix[i][j] = 0;
                rn++;
            }
        for(int j = 0; j < n; j++)
            if((cn < col.size())&&(j == col[cn])){
                for(int i = 0; i < m ;i++)
                    matrix[i][j] = 0;
                cn++;
            }
    }
    
    // 84ms
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), row0_0 = 0, col0_0 = 0;
        // check if row0 = 0
        for(int j = 0; j < n ; j++)
            if(matrix[0][j] == 0){
                row0_0 = 1;
                break;
            }
        // if col 0 = 0
        for(int i = 0; i < m ; i++)
            if(matrix[i][0] == 0){
                col0_0 = 1;
                break;
            }
        // check other elemet ,and save status to row0 and col0
        for(int i = 1 ; i < m ; i++)
            for(int j = 1; j < n ;j++)
                if(matrix[i][j] == 0)
                    matrix[0][j] = matrix[i][0] = 0;
        // make 0
        for(int i = m-1; i > 0 ;i--)
            for(int j = n-1 ; j > 0; j--)
                if(!(matrix[i][0]&&matrix[0][j]))
                    matrix[i][j] = 0;
        // make row 0
        if(row0_0){
            for(int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
        if(col0_0){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
    }
    
    //84ms O(1) space shortest
//    My idea is simple: store states of each row in the first of that row, and store states of each column in the first of that column. Because the state of row0 and the state of column0 would occupy the same cell, I let it be the state of row0, and use another variable "col0" for column0. In the first phase, use matrix elements to set states in a top-down way. In the second phase, use states to set matrix elements in a bottom-up way.
    
    // col0 in charge of each row
    // row0, i = 1 to m-1 in charge of col1 to col(m-1)
    void setZeroes(vector<vector<int>>& matrix) {
        int col0_0 = 0, m = matrix.size(), n = matrix[0].size();
        for(int i = 0 ;i < m ;i++){
            if(matrix[i][0] == 0) col0_0 = 1; // col 0 is 0
            for(int j = 1 ; j< n ;j++ )
                if(matrix[i][j] == 0)
                    matrix[0][j] = matrix[i][0] = 0;
        }
        for(int i = m-1; i >= 0 ; i--){
            for(int j = n-1; j >= 1 ;j-- )
                if((matrix[0][j]==0)||(matrix[i][0]==0))
                    matrix[i][j] = 0;
            if(col0_0) matrix[i][0] = 0;
        }
    }
};