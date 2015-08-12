//
//  Search a 2D Matrix.cpp
//  
//
//  Created by Apple on 15/8/4.
//
//


class Solution {
public:
    
    // O(m+n) slow
    bool searchMatrix(vector<vector<int>> & matrix, int target){
        int m = matrix.size(), n, j(0);
        if (m) n = matrix[0].size();
        else return false;
        for (int i = 0; i < m; i++) {
            for (j = n-1; j >= 0 ; j--) {
                if( matrix[i][j] < target )
                    break;
                else if(matrix[i][j] == target)
                    return true;
            }
        }
        return false;
    }

    // binSearch O(log(mn))
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n;
        if (m) n = matrix[0].size();
        else return false;
        //bisearch row
        int st(0), ed(m*n), mid;
        while (st < ed) {
            mid = (st+ed)/2;
            if( matrix[mid/n][mid-mid/n*n] == target )
                return true;
            if( matrix[mid/n][mid-mid/n*n] < target )
                st = mid+1;
            else
                ed = mid;
        }
        return false;
    }
};