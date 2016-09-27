class Solution {
   public:
      bool isMatch(string s, string p) {
         return helper(s, p, 0, 0);
      }
      bool helper(string s, string p, int i, int j) {
         if (j == p.length())
          return i == s.length();
         if (p[j+1] != '*') {
            if (s[i] == p[j] || (p[j]=='.'&&i!=s.length())){
               return helper(s, p, i+1, j+1);
            }else
             return false;
         }else{
            while(s[i] == p[j] || (p[j]=='.'&& i!=s.length())){
               if (helper(s, p, i, j+2))
                return true;
               i++;
            }
            return helper(s, p, i, j+2);
         }
      }
};
