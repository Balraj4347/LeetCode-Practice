class Solution {
public:
    
    void solve(int k,int n,set<vector<int>> &s,vector<int> &temp )
    {
        if(temp.size()==k && n==0){
            s.insert(temp);
            return;
        }
        
        if(temp.size() < k){
        for (int i = temp.empty() ? 1 : temp.back() + 1; i <= 9; ++i) {
                    if (n - i < 0) break;
                    temp.push_back(i);
                    solve(k, n-i, s, temp);
                    temp.pop_back();
      }
            
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;
        set<vector<int>> s;
        vector<int> temp;
        solve(k,n,s,temp);
   
        for(auto i:s){
            ans.push_back(i);
        }
        
        
        return ans;
    }
};
