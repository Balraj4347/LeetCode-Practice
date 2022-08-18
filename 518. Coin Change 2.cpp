//LINEAR SPACE BOTTOM UP APPROCH
class Solution{
  public:
  int change(int amount,vector<int>& coins{
    vector<int> dp(amount+1,0);
    dp[0]=1;
    for(int i=0;i<coins.size();i++){
      for(int j=1;j<=amount;j++){
        dp[j] = dp[j] + coins[i] <=j ? dp[j-coins[i]] : 0;
      }
    }
    return dp[amount];
  }
}
//T.C : O(amount * coins.size()) ||  S.C: O(amount * coins.size()) stack
//iterative bottom up approch
class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0) return 1;
        if(n == 0) return 0;
        vector<vector<int>> dp(amount+2,vector<int> (n+2,0));
        for(int i=0;i<n+2;i++){
            dp[0][i] =1;
        }
        for(int i=0;i<amount+2;i++){
            dp[i][0] =0;
        }
        for(int i=1;i<amount+1 ;i++){
            for(int j=1;j<n+1;j++){
                if(coins[j-1] > i )
                {
                    dp[i][j]= dp[i][j-1];
                }else{
                    dp[i][j] = dp[i][j-1] + dp[i-coins[j-1]][j];
                }
            }
        }
       
        return dp[amount][n];
    }
};


//T.C : O(amount * coins.size()) ||  S.C: O(amount * coins.size()) stack
//Memoized top down approch
class Solution {
public:
    int solve( vector<int>& coins, int amount, int idx,vector<vector<int>> &dp  ){
        if(idx < 0) return 0;
        if(amount == 0){
            return 1;
        }
        if(dp[amount][idx]!= -1) return dp[amount][idx];
        if(coins[idx] > amount ){
            return dp[amount][idx]= solve(coins,amount,idx-1,dp);
        }
        return dp[amount][idx] =solve(coins,amount-coins[idx],idx,dp) + 
                                solve(coins,amount,idx-1,dp);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0) return 1;
        if(n == 0) return 0;
        vector<vector<int>> dp(amount+1,vector<int> (n,-1));
        return solve(coins,amount,n-1,dp);
        
    }
};
