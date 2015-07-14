//
//  231 Power of Two.cpp
//  
//
//  Created by Apple on 15/7/14.
//
//

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n <= 0 )
            return false;
        while( n ){
            if( (n%2 == 1) && (n != 1) )
                return false;
            n/=2;
        }
        return true;
    }
};