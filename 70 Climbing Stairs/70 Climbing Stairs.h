//
//  70 Climbing Stairs.h
//  
//
//  Created by Apple on 15/7/13.
//
//

#ifndef __0_Climbing_Stairs_h
#define __0_Climbing_Stairs_h

class Solution {
public:
    int climbStairs(int n) {
        if( n < 2 )
            return 1;
        int* m = new int[n+1];
        m[0] = 1;
        m[1] = 1;
        for ( int i = 2; i < n+1; i++ ){
            m[i] = m[i-1] + m[i-2];
        }
        return m[n];
    }
};

#endif
