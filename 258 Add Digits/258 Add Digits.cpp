//
//  258 Add Digits.cpp
//  
//
//  Created by Apple on 15/8/20.
//
//

class Solution {
public:
    
    //https://en.wikipedia.org/wiki/Digital_root
    int addDigits(int num) {
        return num-(num-1)/9*9;
    }
    
    int addDigits(int num) {
        return 1+(num-1)%9;
    }
    
    int addDigits(int num) {
        if(num == 0) return 0;
        if(num%9 == 0) return 9;
        return num%9;
    }
};