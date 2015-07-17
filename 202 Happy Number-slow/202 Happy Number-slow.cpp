//
//  202 Happy Number-slow.cpp
//  
//
//  Created by Apple on 15/7/17.
//
//

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> M;
        M[0] = 0, M[1] = 1, M[2] = 4, M[3] = 9, M[4] = 16, M[5] = 25,\
        M[6] = 36, M[7] = 49, M[8] = 64, M[9] = 81;
        int temp, mark = 0;  
        while(n){
            temp = 0;
            if(n == 1) return true;
            if(n < 10){
                if(mark == n)
                    return false;
                mark = n;
            }
            //calc next n
            while(n){
                temp += (n%10)*(n%10);    //4ms
//                temp += M[n%10];  // 8ms
                n /= 10;
            }
            n = temp;
        }
    }
};