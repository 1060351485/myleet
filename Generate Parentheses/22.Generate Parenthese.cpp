class Solution {
   public:
      vector<string> rslt;
      void helper(int n, int left, int right, string tmp) {
         if (left == n){
            while(tmp.length()!=2*n)
             tmp += ')';
            rslt.push_back(tmp);
            return;

         }
         helper(n, left+1, right, tmp+'(');
         if (right < left)
          helper(n, left, right+1,tmp+')');
      }
      vector<string> generateParenthesis(int n) {
         if (n == 0)
          return rslt;
         helper(n, 0, 0, "");
         return rslt;
      }
};

class Solution {
   public:
      vector<string> generateParenthesis(int n) {
         vector<string> res;
         addingpar(res, "", n, 0);
         return res;

      }
      void addingpar(vector<string> &v, string str, int n, int m){
         if(n==0 && m==0) {
            v.push_back(str);
            return;

         }
         if(m > 0){ addingpar(v, str+")", n, m-1);  }
         if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
      }
};
