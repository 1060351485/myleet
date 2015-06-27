//
//  14 Longest Common Prefix.cpp
//  
//
//  Created by Apple on 15/6/27.
//
//

class Solution {
public:
    
    string commonPrefixInTwo( string stra, string strb ){
        int lena = stra.length();
        int lenb = strb.length();
        int i = 0;
        string comStr = "";
        int minlen = (lena<= lenb)?lena:lenb;
        while ( i < minlen ){
            if (stra[i] == strb[i]){
                comStr += stra[i];
                i++;
            }else{
                break;
            }
        }
        return comStr;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if ( size == 0 )
            return "";
        else if ( size == 1 )
            return strs[0];
        string rslt = strs[0];
        for ( int i = 1 ;i < size; i++){
            rslt = commonPrefixInTwo(rslt, strs[i]);
            if ( rslt == "" )
                return "";
        }
        return rslt;
    }
    
};