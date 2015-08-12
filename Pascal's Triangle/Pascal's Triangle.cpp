//
//  Pascal's Triangle.cpp
//  Pascal's Triangle
//
//  Created by Apple on 15/8/4.
//  Copyright (c) 2015年 hjh. All rights reserved.
//

// from left to right
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> v(numRows);
    if(numRows) v[0].push_back(1);
    for(int i = 1 ;i < numRows ; i++){
        v[i].push_back(1);
        for(int j = 1; j < i; j++)
            if(j <= v[i-1].size())
                v[i].push_back(v[i-1][j] + v[i-1][j-1]);
        v[i].push_back(1);
    }
    return v;
}

// from right to left
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> v;
    vector<int> tempV;
    for (int i = 0 ; i < numRows; i++) {
        tempV = vector<int>(i,1);
        for (int j = i-1; j > 0; j--)
            tempV[j] = v[i-1][j] + v[i-1][j-1];
        tempV.push_back(1);
        v.push_back(tempV);
    }
    return v;
}