class Solution {
public:

    
    int coinChange(vector<int>& coins, int amount) {
     vector<int>dp(amount+1);
        dp[0]=0;
        
        for(int i=1;i<=amount;i++){
            dp[i]=INT_MAX;
            for(int j:coins)
            {
                if(i-j < 0) continue;
                if(dp[i-j] != INT_MAX) dp[i]= min( dp[i-j]+1,dp[i]);
                
            }
            
        }
        return dp[amount] == INT_MAX ? -1: dp[amount];
        
    }
};
