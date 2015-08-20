//
//  263 Ugly Number.cpp
//  
//
//  Created by Apple on 15/8/20.
//
//

class Solution {
public:
    
    bool isUgly(int num) {
        if(num <= 0) return false;
        if(num == 1) return true;
        if(num%2 == 0) return isUgly(num/2);
        if(num%3 == 0) return isUgly(num/3);
        if(num%5 == 0) return isUgly(num/5);
        return false;
    }
    
    bool isUgly(int num) {
        if(num <= 0) return false;
        while(num%2 == 0) num/=2;
        while(num%3 == 0) num/=3;
        while(num%5 == 0) num/=5;
        return num == 1;
    }
};