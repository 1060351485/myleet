//
//  Search a 2D Matrix II.cpp
//  
//
//  Created by Apple on 15/8/5.
//
//

class Solution {
public:
    
    //304ms O(m+n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n;
        if (m) n = matrix[0].size();
        else return false;
        int i(0),j(n-1);
        while ((i < m)&&(j >=0)) {
            if(matrix[i][j] == target)
                return true;
            if(matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
};