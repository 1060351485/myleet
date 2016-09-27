class Solution {
   vector<string> rslt;
   vector<string> v = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
   public:
   void helper(string digits, string tmp){
      int m = digits.length();
      int n = tmp.length();
      if (m == n){
         rslt.push_back(tmp);
         return;
      }
      for (int i = 0; i < v[digits[n]-'0'].length(); i++){
         helper(digits, tmp+v[digits[n]-'0'][i]);
      }
   }
   vector<string> letterCombinations(string digits) {
      if (digits.empty())
       return rslt;
      helper(digits, "");
      return rslt;
   }
};
