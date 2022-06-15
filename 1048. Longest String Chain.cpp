//Bottom Up Dp approch with a unordered_map to store the length of the predecessor at a index 

class Solution {
public:
  
    int longestStrChain(vector<string>& words) {
        
       sort(words.begin(),words.end(), 
            [](string a, string b){ return a.length() < b.length();});
        int ans=1;
        unordered_map<string,int> dp;
        
        for(int i=0;i<words.size();i++){
            dp[words[i]]= 1;
            for(int j=0;j<words[i].size();j++)
            {
                string sub = words[i].substr(0,j) + words[i].substr(j+1);
                if(dp.find(sub) != dp.end() ){
                    dp[words[i]]= dp[sub] +1;
                    ans= max(ans,dp[words[i]]);
                }
            }
            
        }
        return ans;
    }
};
