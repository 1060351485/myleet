//
//  Pascal's Triangle II.cpp
//
//
//  Created by Apple on 15/8/4.
//  Copyright (c) 2015年 hjh. All rights reserved.
//

class Solution {
public:
    
    // from right to left
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1,1);
        for(int i = 0 ;i < rowIndex+1 ; i++)
            for(int j = i-1 ; j > 0 ; j--)
                v[j] += v[j-1];
        return v;
    }
    
    
    //from left to right
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1,1);
        int vj_old, vjm_old(1);   // v[j] = v[j] + v[j-1]old <= vjminus
        for(int i = 0 ;i < rowIndex+1 ; i++){
            for(int j = 1 ; j < i ; j++){
                vj_old = v[j];
                v[j] = v[j] + vjm_old;
                vjm_old = vj_old;
            }
        }
        return v;
    }
};
