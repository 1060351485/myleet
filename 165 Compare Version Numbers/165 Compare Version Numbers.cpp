//
//  165 Compare Version Numbers.cpp
//  
//
//  Created by Apple on 15/7/16.
//
//

class Solution {
public:
    
    int strToInt( string s,int& strt ){
        int rslt = 0;
        while(isdigit(s[strt]))
            rslt = rslt*10 + s[strt++]-'0';
        return rslt;
    }
    
    int compareVersion(string version1, string version2) {
        int ver1 = 0, ver2 = 0;
        int i = 0, j = 0;
        while( (i != version1.length())||(j != version2.length()) ){
            ver1 = strToInt( version1, i );
            ver2 = strToInt( version2, j );
            if(ver1 < ver2)
                return -1;
            if(ver1 > ver2)
                return 1;
            if(i != version1.length())
                i++;
            if(j != version2.length())
                j++;
        }
        if( ver1 == ver2 )
            return 0;
    }
    
};