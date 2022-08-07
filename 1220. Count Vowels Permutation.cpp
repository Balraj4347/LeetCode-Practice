//A better top down dp approch  T.C: O(5*n) S.C: O(n)
class Solution {
public:
    const unsigned int MOD = 1e9+7;
    unordered_map<char,vector<char>> M;
    unordered_map<char,vector<int> > dp;
    void init(){
        M = {
            {'s',{'a','e','i','o','u'}},
            {'a',{'e'}}, {'e',{'a','i'}}, 
            {'i',{'a','e','o','u'}}, 
            {'o',{'i','u'}}, {'u',{'a'}} 
        };
        

    }
    
    int countVowelPermutation(int n) {
        init();
        dp['s']=dp['a']=dp['e']= dp['i']= dp['o']= dp['u']= vector<int>(n+1);
        return solve(n,'s');
    }
    
    int solve(int rem, char prev){
        if(rem ==0 ) return 1;
        if(dp[prev][rem] ) return dp[prev][rem];

        for(char c: M[prev]){
            dp[prev][rem] = (dp[prev][rem] + solve(rem-1,c))% MOD;
        }
        return dp[prev][rem];
    }
};


// First Hit approch T.C : O(5*5*N) S.C: O(1)
class Solution {
public:
    const unsigned int mod = 1000000007;
    unordered_map<char,vector<char>> M;
    void init(){
        M = {
            {'a',{'e'}}, {'e',{'a','i'}}, 
            {'i',{'a','e','o','u'}}, 
            {'o',{'i','u'}}, {'u',{'a'}} 
        };

    }
    int countVowelPermutation(int n) {
        init();
        unordered_map<char, unsigned int > prev;
        prev = {
            {'a',1}, {'e',1}, {'i',1}, {'o',1}, {'u',1} 
        };
        
        for(int i=2;i<=n;i++){
            unordered_map<char,unsigned int> curr;
            for(auto item : prev ){
                for(char a : M[item.first])
                    curr[a] = (curr[a] + item.second) % mod;
            }
            prev= curr;
        }
        unsigned int ans=0 ;
        for(auto item : prev){
            ans = (ans + item.second )% mod ;
        }
        return ans;
    }
};
