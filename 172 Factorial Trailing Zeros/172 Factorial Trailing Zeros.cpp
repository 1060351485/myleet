//
//  172 Factorial Trailing Zeros.cpp
//  
//
//  Created by Apple on 15/7/17.
//
//

class Solution {
public:
    // count 5,5*5,5*5*5... add up
    int trailingZeroes(int n) {
        int rslt = 0;
        while(n/5){
            rslt += n/5;
            n/=5;
        }
        return rslt;
    }
};