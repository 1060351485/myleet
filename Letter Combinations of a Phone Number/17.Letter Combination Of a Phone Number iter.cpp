vector<string> letterCombinations(string digits) {
   vector<string> rslt;
   if (digits.empty()) return rslt;
   rslt.push_back("");
   vector<string> v = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
   for (int i = 0; i < digits.length(); i++){
      vector<string> tmp;
      string charset = v[digits[i]-'0'];
      for (int j = 0; j < charset.size(); j++)
       for (int k = 0; k < rslt.size(); k++)
        tmp.push_back(rslt[k]+charset[j]);
      rslt = tmp;
   }
   return rslt;
}
