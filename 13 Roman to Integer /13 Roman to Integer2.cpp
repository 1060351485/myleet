//
//  13 Roman to Integer2.cpp
//  Roman to Integer
//
//  Created by Apple on 15/6/27.
//  Copyright (c) 2015年 hjh. All rights reserved.
//

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int l = s.length();
        sum += charToInt(s[l-1]);
        for (int i=l-2; i >= 0 ; i--){
            if( charToInt(s[i]) < charToInt(s[i+1]) )
                sum -= charToInt(s[i]);
            else
                sum += charToInt(s[i]);
        }
        return sum;
    }
    
    int charToInt( char c ){
        switch(c){
            case('M'):{ return 1000; }
            case('D'):{ return  500; }
            case('C'):{ return  100; }
            case('L'):{ return   50; }
            case('X'):{ return   10; }
            case('V'):{ return    5; }
            case('I'):{ return    1; }
            default : return 0;
        }
    }
};