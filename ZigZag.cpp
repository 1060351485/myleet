//
//  main.cpp
//  ZigZag Conversion
//
//  Created by Apple on 15/6/26.
//  Copyright (c) 2015年 hjh. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string convert(string s, int numRows) {
    long len = s.length();
    if (( 1 == len )||( numRows == 1 )||(numRows > len ))
        return s;
    string rslt = "";
    int off = 0;  // how many groups
    int c1 = 0, c2 = 0;
    for( int i = 0; i< numRows ; i++){
        off = 1;
        rslt += s[i];
        while( 1 ){
            if ( i != numRows-1 ){
                c1 = off * (2*numRows-2) -i;
                if ( c1 < len ){
                    rslt += s[c1];
                }else{
                    break;
                }
            }
            if (( i != 0 )){
                c2 = off * (2*numRows-2) + i;
                if ( c2 < len ){
                    rslt += s[c2];
                }else{
                    break;
                }
            }
            off++;
        }
    }
    return rslt;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<convert("AB", 3);
    cout<<convert("AB", 3).length();
    return 0;
}
