//
//  28 Implement strStr().cpp
//  
//
//  Created by Apple on 15/6/29.
//
//

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        if(haystack.empty()&&!needle.empty())
            return -1;
        if (haystack.size() < needle.size()){
            return -1;
        }
        int i = 0;
        bool get = false;
        while( i < haystack.size()-needle.size()+1 ){
            if ( haystack.substr(i,needle.size()) == needle ){
                get = true;
                return i;
            }
            i++;
        }
        if(!get)
            return -1;
    }
};