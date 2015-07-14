//
//  168 Excel Sheet Column Title.cpp
//  
//
//  Created by Apple on 15/7/14.
//
//

class Solution {
public:
    string convertToTitle(int n) {
        string rslt = "";
        while( n ){
            if( n%26 == 0 ){
                n -= 26;
                rslt.insert(0, 1, 'Z');
            }else{
                rslt.insert(0, 1, char(n%26+'A'-1));
            }
            n /= 26;
        }
        return rslt;
    }
};