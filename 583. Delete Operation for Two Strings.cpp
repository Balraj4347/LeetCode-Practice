

//dp recursive memoization approch  time: O(m*n) space:O(m*n) 
class Solution {
public:

    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        int lcs = helper(word1, word2, m, n, memo);
        int steps = (m-lcs) + (n-lcs);
        return steps;
    }
    
    int helper(string& word1, string& word2, int m, int n,          
                vector<vector<int>>& memo)
    {
        if(m == 0 || n == 0) return 0;
        
        if(memo[m][n] != -1)
            return memo[m][n];
        
        if(word1[m-1] == word2[n-1])
            return memo[m][n] = 1 + helper(word1, word2, m-1, n-1, memo);
        else
            return memo[m][n] = max(
                                    helper(word1, word2, m-1, n, memo), 
                                    helper(word1, word2, m, n-1, memo)
                                );
    }
};

//dp bottom-up tabulation approch time: O(m*n) space:O(m*n) iterative
class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m= word1.length();
        int n= word2.length();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++)    
                dp[i][0] = 0;
        for(int j=0;j<=n;j++)   
                dp[0][j] = 0;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
          if(word1[i-1] == word2[j-1])        
              dp[i][j] = dp[i-1][j-1] + 1;
          else 
              dp[i][j] = max(dp[i-1][j],dp[i][j-1]);  
        }
    return m - dp[m][n] + n - dp[m][n];
    }
};
