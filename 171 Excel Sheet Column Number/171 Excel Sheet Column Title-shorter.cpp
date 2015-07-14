//
//  171 Excel Sheet Column Title-shorter.cpp
//  
//
//  Created by Apple on 15/7/14.
//
//
//因为a到z是1到26，然后每次除法的时候除的也是26，所以按照一般方法算会出问题
//  a*(26^2) + b*(26^1)+ z
//按照原来的方法，Z每次多一，其他的情况也会－1，所以合成一种方法

string convertToTitle(int n) {
    string rslt = "";
    while(n){
        rslt = char((n-1)%26 + 'A') + rslt;
        n = (n-1)/26;
    }
    return rslt;
}