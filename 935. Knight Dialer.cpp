class Solution {
public:
   vector<vector<int>>keypad ={ {4,6},{8,6},{7,9},{4,8},{3,9,0},{},{1,7,0},
                                {2,6},{1,3},{2,4} };
    
    int mod= pow(10,9)+7;
    int solve(int pos,int lefthops, vector<vector<int>>& dp){
        
        if(lefthops == 0)
            return 1;
        
        if(dp[pos][lefthops] != -1)
            return dp[pos][lefthops];
        
        long long temp=0;
        for(auto i: keypad[pos])
        temp = ( temp % mod + solve(i,lefthops-1,dp) % mod );
        
        dp[pos][lefthops]=temp %mod ;
        
        
        return dp[pos][lefthops];
    }
    int knightDialer(int n) {
        
        long long rslt=0;
        vector<vector<int>> dp(10, vector<int>(n,-1));
        for(int i=0;i<10;i++){
                rslt+= solve(i,n-1,dp);
        }
        return rslt % mod;
    }
};
