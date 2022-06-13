//Bottom-UP approch 

class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
         vector<int> mini = triangle[triangle.size()-1];
        for ( int i = triangle.size() - 2; i>= 0 ; --i )
            for ( int j = 0; j < triangle[i].size() ; ++ j )
                mini[j] = triangle[i][j] + min(mini[j],mini[j+1]);
        return mini[0];
       
    }
};


//TOP_DOWN RECURSIVE APPROCH. Very Bad Space optimisation🥲
class Solution {
public:
    int helper(vector<vector<int>>& triangle,int i,
               int pos,vector<vector<int>>& dp)
    {   
        int n= triangle.size();
        if( i == n-1){
            return triangle[i][pos];
        }
        int left,right;
        if(dp[i+1][pos]!=10001)
            left= dp[i+1][pos];
        else
             left = helper(triangle,i+1,pos,dp);
        
        if(dp[i+1][pos+1]!= 10001)
            right= dp[i+1][pos+1];
        else
            right= helper(triangle,i+1,pos+1,dp);
        
        dp[i][pos] = min(left,right) + triangle[i][pos];
     
        
        return dp[i][pos];
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int max= triangle[n-1].size();

        vector<vector<int>> dp(n,vector<int>(max, 10001));
        
        return helper(triangle,0,0,dp);
       
    }
};
