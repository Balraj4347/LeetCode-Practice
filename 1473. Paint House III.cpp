class Solution {
public:
    int dp[101][101][21]={};
    int solve(vector<int>& houses,vector<vector<int>>& cost, int index,int prev, int target){
        
        if(index == houses.size() || target<0)
            return target == 0? 0:1000001;
        if(dp[index][target][prev] != -1)
            return dp[index][target][prev];
        if( houses[index]!=0 )
            return solve(houses,cost,index+1,houses[index],target-(prev!=houses[index]));
        
        auto ans=1000001;
        for(int i=1;i<=cost[0].size();i++){
            ans = min(ans, cost[index][i-1]+solve(houses,cost,index+1,i,target-
                                 (prev!=i)));
        }
        
        return dp[index][target][prev] = ans;
        
        
    }
                              
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp) );
        int ans = solve(houses,cost,0,0,target);
        
        return ans>1000000 ? -1 : ans;
    }
};
