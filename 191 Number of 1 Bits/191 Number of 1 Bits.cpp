//
//  191 Number of 1 Bits.cpp
//  
//
//  Created by Apple on 15/7/14.
//
//

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while( n ){
            if( n%2 == 1 )
                count++;
            n/=2;
        }
        return count;
    }
};