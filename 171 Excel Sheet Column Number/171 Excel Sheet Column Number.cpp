//
//  171 Excel Sheet Column Number.cpp
//  
//
//  Created by Apple on 15/7/14.
//
//

class Solution {
public:
    int titleToNumber(string s) {
        int i = 0, rslt = 0, x = 1;
        while( i < s.length() )
            rslt = rslt*26 + (s[i++]-'A'+1);
        return rslt;
    }
};