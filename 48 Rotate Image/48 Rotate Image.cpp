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
    
    //Basically, divide the array into 4 along the diagonals, then for each element in the top quadrant, place it into the slot 90 degrees cw, and the old 90 in 180 degrees cw, and the old 180 in 270 degrees , and the old 270 in the original place.
//    x x x x x
//    x x x x x
//    x x x x x
//    x x x x x
//    x x x x x
//    
//    n = 5
//    (1,1)->(1,3)  (0,1)->(1,4)
//    (1,3)->(3,3)  (1,4)->(4,3)
//    (3,3)->(3,1)  (4,3)->(3,0)
//    (3,1)->(1,1)  (3,0)->(0,1)
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp;
        for( int i = 0 ; i <= n/2; i++){
            for(int j = i; j < n-i-1; j++){
                temp = move(matrix, matrix[i][j], j, n-1-i);
                temp = move(matrix, temp, n-1-i, n-1-j);
                temp = move(matrix, temp, n-1-j, i);
                move(matrix, temp, i, j);
            }
        }
        
    }
    
    int move(vector<vector<int>>& matrix, int a, int i, int j){
        int temp = matrix[i][j];
        matrix[i][j] = a;
        return temp;
    }
    
    };