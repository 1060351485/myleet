//
//  Multiply Strings.cpp
//  
//
//  Created by Apple on 15/8/6.
//
//

class Solution {
public:
    
    // so slow 80ms
    string add2string(string a, string b){
        string rslt = "";
        int m = a.length()-1;
        int n = b.length()-1;
        int carry(0), in1(0), in2(0);
        while ((m >= 0)||(n >= 0)||carry) {
            in1 = (m >= 0)?a[m--] - '0':0;
            in2 = (n >= 0)?b[n--] - '0':0;
            rslt = char((carry + in1 + in2)%10+'0') + rslt;
            carry = (in1 + in2 + carry) / 10;
        }
        return rslt;
    }
    
    string multipliyChar(string num, char c){  //"543534"*'4'
        string rslt = "";
        if (c == '0')
            return "0";
        int carry(0);
        for (int i = num.length()-1; i >= 0; i--) {
            carry = (num[i]- '0') *(c - '0') + carry;
            rslt = char(carry%10 + '0') + rslt;
            carry = carry/10;
        }
        if (carry%10 != 0)
            rslt = char(carry%10 + '0') + rslt;
        return rslt;
    }
    
    string multiply(string num1, string num2) {
        string rslt = "";
        string tempMul = "";
        int m = num1.length()-1;
        int n = num2.length()-1;
        for (int j = n ; j >= 0; j--) {
            tempMul = add2string(tempMul, multipliyChar(num1, num2[j]));
            rslt = tempMul[tempMul.length()-1] + rslt;
            tempMul.erase(tempMul.end()-1);
        }
        rslt = tempMul + rslt;
        int st = 0;
        while ((rslt[st] == '0')&&(st != rslt.length()-1)) // get rid of initial '0'
            rslt.erase(rslt.begin());
        return rslt;
    }
};