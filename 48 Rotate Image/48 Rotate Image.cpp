//
//  48 Rotate Image.cpp
//  
//
//  Created by Apple on 15/8/2.
//
//

class Solution {
public:
    // left swap 3 times
    //  n%2 == 1?
    //  n%2=0
    //  y y x x      z z x x    z z x x     z z y y
    //  y y x x      z z x x    z z x x     z z y y
    //  z z w w   => y y w w => w w y y  => w w x x
    //  z z w w      y y w w    w w y y     w w x x
    //
    //  n%2=1
    //  y y y x x    z z z x x    z z z x x     z z z y y
    //  y y y x x    z z z x x    z z z x x     z z z y y
    //  z z t x x => y y t x x => w w t x x =>  w w t y y
    //  z z w w w    y y w w w    w w y y y     w w x x x
    //  z z w w w    y y w w w    w w y y y     w w x x x
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        for( int i = 0 ; i <= n/2-1; i++)
            for(int j = 0; j <= (n-1)/2; j++)
                matrix[i][j] ^= matrix[n-1-j][i] ^= matrix[i][j] ^= matrix[n-1-j][i];
        
        for( int i = n/2 ; i <= n-1; i++)
            for(int j = 0; j <= n/2-1; j++)
                matrix[i][j] ^= matrix[n-1-j][i] ^= matrix[i][j] ^= matrix[n-1-j][i];
        
        for( int i = (n+1)/2 ; i <= n-1; i++)
            for(int j = n/2; j <= n-1; j++)
                matrix[i][j] ^= matrix[n-1-j][i] ^= matrix[i][j] ^= matrix[n-1-j][i];
        
    }
};