//
//  165 Compare Version Numbers-sstream.cpp
//  Compare Version Numbers
//
//  Created by Apple on 15/7/16.
//  Copyright (c) 2015年 hjh. All rights reserved.
//

class Solution {
public:
    
    int compareVersion(string version1, string version2) {
        for( auto& w: version1 ) if(w == '.') w = ' ';
        for( auto& w: version2 ) if(w == '.') w = ' ';
        istringstream s1(version1), s2(version2);
        while(1){
            int n1,n2;
            if(not(s1>>n1)) n1 = 0;
            if(not(s2>>n2)) n2 = 0;
            if( not s1 && not s2 ) return 0;
            if(n1 < n2) return -1;
            if(n1 > n2) return 1;
        }
    }
    
};
