//
//  191 Reverse Bits.cpp
//  
//
//  Created by Apple on 15/7/14.
//
//

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        int i = 0;
        while( i<32 ){
            m *= 2;
            m += n%2;
            n /= 2;
            i++;
        }
        return m;
    }
};