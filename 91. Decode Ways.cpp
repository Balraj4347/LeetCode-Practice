//top down approch 0 >>> n
class Solution {
public:
    
    int solve(int index, string s,int n, vector<int>& dp)
    {   
        
        if(dp[index]!= -1) return dp[index];
        if(s[index] == '0') return dp[index]=0;
        
        int temp = solve(index+1,s,n,dp);
    
    if( index < n-1 && (s[index]=='1'|| (s[index]=='2'&& s[index+1]<'7'))) 
      temp +=solve(index+2,s,n,dp);
    
        
        return dp[index]=temp;
        
    }
    int numDecodings(string s) {
     
        if(s.empty())
         return 0;

        int n= s.size();
        vector<int> dp(n+1,-1);
        dp[n]=1;
 
        return solve(0,s,n,dp);
    }
};

// bottom up approch space 
class Solution {
public:

    int numDecodings(string s) {
     
        if(s.empty())
         return 0;
        int n= s.size();
        vector<int> dp(n+1,-1);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0') dp[i]=0;
            else{
                dp[i]=dp[i+1];
                 if(i<n-1 && (s[i]=='1'||s[i]=='2'&&s[i+1]<'7')) dp[i]+=dp[i+2];
            }
            
        }
 
        return dp[0];
    }
};
