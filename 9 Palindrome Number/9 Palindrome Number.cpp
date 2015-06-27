//
//  9 Palindrome Number.cpp
//  
//
//  Created by Apple on 15/6/27.
//
//

class Solution {
public:
    int reverse(int x) {
        
        bool neg = false;
        if ( x < 0 ){
            if ( x <= INT32_MIN )
                return 0;
            neg = true;
            x = -x;
        }
        
        long reg = 0;
        while( x/10 ){
            reg = reg*10 + x % 10;
            x /= 10;
        }
        reg = reg*10 + x%10;
        
        if ( reg > 0x7fffffff) // overflow check
            return 0;
        if ( neg )
            return (-1)*(int)reg;
        else
            return (int)reg;
    }
    
    bool isPalindrome(int x) {
        if ( x < 0 )
            return false;
        return x == reverse(x);
    }
};