//
//  7 Reverse Integer.cpp
//  Reverse Integer
//
//  Created by Apple on 15/6/26.
//  Copyright (c) 2015年 hjh. All rights reserved.
//
class Solution {
public:
    int reverse(int x) {
        
        bool neg = false;
        if ( x < 0 ){
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
            return (int)reg;
        else
            return (-1)*(int)reg;
    }
    
};
