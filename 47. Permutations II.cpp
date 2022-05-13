/*
1st Submission 
*/

class Solution {
public:
    
    void solve(vector<int> &nums, set<vector<int>> & s, vector<int> t){
        if(t.size()== nums.size()){
            s.insert(t);
        return;}
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i]!=12){
            if(i>0 && nums[i]==nums[i-1]) continue; 
                int j=nums[i];
                t.push_back(nums[i]);
                nums[i]=12;
                solve(nums,s,t);
                nums[i]=j;
                t.pop_back();
                
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>> s;
        vector<vector<int>> ans;
        
        solve(nums,s,{});
        for(auto i:s )
            ans.push_back(i);
        return ans;
    }
};

/*
fast solution using in built next_permutation
*/
class Solution {
public:
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>v;
         sort(nums.begin(),nums.end());
        v.push_back(nums);
        while(next_permutation(nums.begin(),nums.end()))v.push_back(nums);
        return v;
        
    }
};
