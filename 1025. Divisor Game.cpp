class Solution {
public:
    int dp[1001];
    bool divisorGame(int n) {
        if(dp[n] == 0){
            for(int i=1;dp[n]!=1 && i<=n/2;i++)
                dp[n] = n%i ==0 ? divisorGame(n-i) ? -1 : 1 : -1;
            }
        
        return dp[n]==1;
    }
};
