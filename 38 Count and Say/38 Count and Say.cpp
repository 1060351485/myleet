//
//  38 Count and Say.cpp
//  
//
//  Created by Apple on 15/6/30.
//
//

class Solution {
public:
    string countAndSay(int n) {
        string base = "1";
        string temp = "";
        int i = 0;
        string count = "1";
        while( --n ){
            i = 0;
            temp = "";
            while( i < base.length() ){
                if(base[i] == base[i+1]){
                    count[0]++;
                }else{
                    temp += count[0];
                    temp += base[i];
                    count = "1";
                }
                i++;
            }
            base = temp;
        }
        return base;
    }
};