//
//  8 String to Integer (atoi).cpp
//  
//
//  Created by Apple on 15/6/27.
//
//

class Solution {
public:
    int myAtoi(string str) {
        long rslt = 0;  // in case overflow
        int i = 0;  // string index
        int temp;  // temp char
        bool neg = false;
        bool count_start = false; // find another '+','-',' ' return 0 or rslt
        while( str[i] ){
            if ( str[i] != ' '){  // if haven't start, remove first ' ',else return rslt
                if( str[i] == '+' ){
                    if ( count_start == true )
                        return 0;
                    else
                        count_start = true;
                }else{
                    if (str[i] == '-'){
                        neg = true;
                        if ( count_start == true )
                            return 0;
                        else
                            count_start = true;
                    }else{
                        count_start = true;
                        temp = str[i] - '0';
                        if(( temp >= 0 )&&( temp <=9 )){
                            rslt = rslt*10 + temp;
                            if  ((neg == false)&&(rslt > INT32_MAX))
                                return INT32_MAX;
                            else if (( neg == true )&&( (-1)*rslt < INT32_MIN ))
                                return INT32_MIN;
                        }else{
                            break;
                        }
                    }
                }
            }else{
                if (count_start == true)
                    return rslt;
            }
            i++;
        }
        if(neg){
            return (-1)*(int)rslt;
        }else{
            return (int)rslt;
        }
    }
};