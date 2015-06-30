//
//  58 Length of Last Word.cpp
//  
//
//  Created by Apple on 15/6/30.
//
//

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        int noSpace = 0;
        
        while(s[i] == ' ') i-- ; // remove last ' '
        
        noSpace = i;
        while( ( i >= 0 )&&(s[i]!= ' ') )
            i--;
        return noSpace-i; // if all ' ',noSpace == i,return 0
    }
    
};