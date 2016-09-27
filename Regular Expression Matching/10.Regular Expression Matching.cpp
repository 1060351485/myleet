class Solution {
   public:
      bool isMatch(string s, string p) {
         int m = s.length();
         int n = p.length();
         //     1. P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
         //     2. P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
         //     3. P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.
         vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
         dp[0][0] = true;
         for (int i = 0; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
               if (p[j-1] != '*')
                dp[i][j] = i > 0 && dp[i-1][j-1] &&(s[i-1]==p[j-1] || p[j-1]=='.');
               else
                dp[i][j] = dp[i][j-2] || (i>0&&dp[i-1][j]&&(s[i-1]==p[j-2]||p[j-2]=='.'));
            }
         }
         return dp[m][n];
      }
};
