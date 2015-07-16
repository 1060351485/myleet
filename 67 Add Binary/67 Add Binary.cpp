//
//  67 Add Binary.cpp
//  
//
//  Created by Apple on 15/7/16.
//
//

class Solution {
public:
    string addBinary(string a, string b) {
        int abit = 0, bbit = 0, carry = 0;
        int aposi = a.length()-1;
        int bposi = b.length()-1;
        string rslt = "";
        while( (aposi >=0)||(bposi >= 0) || carry ) {
            abit = 0, bbit = 0;
            if(aposi>=0) abit = a[aposi--] == '1';
            if(bposi>=0) bbit = b[bposi--] == '1';
            rslt = static_cast<char>(abit^bbit^carry + '0') + rslt;
            carry = abit + bbit + carry >=2;
        }
        return rslt;
    }
};