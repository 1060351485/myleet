//
//  36 Valid Sudoku.cpp
//  
//
//  Created by Apple on 15/7/2.
//
//

#include <math.h>

class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool u1[9][9] = {0};
        bool u2[9][9] = {0};
        bool u3[9][9] = {0};
        int t = 0;
        int index = 0;
        for ( int i = 0;i < 9;i++){
            for( int j = 0 ;j < 9 ; j++ ){
                if ( board[i][j] != '.' ){
                    t = board[i][j]-'1';
                    index = i/3*3+j/3;
                    if( u1[i][t] || u2[j][t] || u3[index][t] )
                        return false;
                    else
                        u1[i][t] = u2[j][t] = u3[index][t] = 1;
                }
            }
        }
        return true;
    }
};