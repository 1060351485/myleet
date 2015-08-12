//
//  Pow.cpp
//  
//
//  Created by Apple on 15/8/6.
//
//

class Solution {
public:
    
    //ac
    double pow_n(double x, int exp){
        if((exp == 0)||(x == 1)) return 1;
        if(x == -1) return exp%2==1?-1:1;
        if(x == 0) return 0;
        if(exp%2 == 0){
            double v =pow_n(x, exp/2);
            return v*v;
        }
        else return pow_n(x, exp-1)*x;
    }
    
    double myPow(double x, int n) {
        if(n >= 0)
            return pow_n(x, n);
        else
            return 1.0/pow_n(x, -n);
    }
    
    //4ms
    double myPow(double x, int n) {
        if((x == 1)||(n == 0)) return 1;
        if(x == -1) return n%2==1?-1:1;
        if(x == 0) return 0;
        if(n > 0){
            if(n%2 == 0){
                double v =myPow(x, n/2);
                return v*v;
            }
            else return myPow(x, n-1)*x;
        }else
            return 1.0/myPow(x, -n);
    }
};