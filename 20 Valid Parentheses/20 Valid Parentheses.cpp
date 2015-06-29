//
//  20 Valid Parentheses.cpp
//  
//
//  Created by Apple on 15/6/29.
//
//

class Solution {
public:
    bool isValid(string s) {
        stack<char> bracS;
        int i = 0;
        while( s[i] ){
            if(!bracS.empty())
                if ((s[i] == bracS.top()+1)||(s[i] == bracS.top()+2))  // ASCII
                    bracS.pop();
                else
                    bracS.push(s[i]);
                else
                    bracS.push(s[i]);
            i++;
        }
        return bracS.empty();
    }
    
};