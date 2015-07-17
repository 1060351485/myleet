//
//  165 Compare Version Numbers.cpp
//  
//
//  Created by Apple on 15/7/16.
//
//

class Solution {
public:
    
    int compareVersion(string version1, string version2) {
        int ver1 = 0, ver2 = 0;
        int i = 0, j = 0;
        while( (i != version1.length())||(j != version2.length()) ){
            while(isdigit(version1[i]))
                ver1 = ver1*10 + version1[i++]-'0';
            while(isdigit(version2[j]))
                ver2 = ver2*10 + version2[j++]-'0';
            if(ver1 < ver2)
                return -1;
            if(ver1 > ver2)
                return 1;
            ver1 = 0, ver2 = 0;
            if(i != version1.length())
                i++;
            if(j != version2.length())
                j++;
        }
        return 0;
    }
    
    
    // move last lines into loop
    int compareVersion(string version1, string version2) {
        int ver1 = 0, ver2 = 0;
        int i = 0, j = 0;
        int m = version1.length(), n = version2.length();
        while( (i < m)||(j < n) ){
            while(isdigit(version1[i])&&(i<m))
                ver1 = ver1*10 + version1[i++]-'0';
            while(isdigit(version2[j])&&(j<n))
                ver2 = ver2*10 + version2[j++]-'0';
            if(ver1 < ver2)
                return -1;
            if(ver1 > ver2)
                return 1;
            ver1 = 0, ver2 = 0;
            i++;
            j++;
        }
        return 0;
    }
};