class Solution {
public:

    vector<int> countBits(int n) {
        vector<int> ans(n+1,-1);
        ans[0]=0;
        for(int i=1;i<=n;i++)
            ans[i]=ans[i/2]+ (i%2);
        return ans;
        
        
    }
};


////////////another solution , 1st try
class Solution {
public:
    int solve(int n, vector<int> &ans){
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        
        if(ans[n] != -1){
            return ans[n];    
        }
        ans[n]= solve(n/2,ans) + int(n%2);
        if(n>0){solve(n-1,ans);}
        cout<<n<<" ";
        return ans[n];
    
        
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,-1);
        ans[0]=0;
        if(n>0){ans[1]=1;}
        int p =solve (n,ans);
        return ans;
        
        
    }
};
