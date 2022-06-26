//T.c: O(n). S.C : O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        if(nums.empty())return {};
        int n=nums.size();
       
        vector<int> result;
        
        for(int i=0;i<n;i++){
            
            if(nums[ abs( nums[i] )-1 ] < 0)
                result.push_back( abs(nums[i]) );
            else
                nums[abs(nums[i])-1]*= -1;
           
        }
        
        return result;
    
    }
};

//t.c: O(n).  s.c. : O(n);
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> sign(n+1,-1);
        
        for(int i=0;i<n;i++){
            
            sign[nums[i]]=sign[nums[i]]+ 1;
        }
        vector<int> result;
        for(int i=1;i<=n;i++){
            if(sign[i]>0)
                result.push_back(i);
        }
        
        return result;
    
    }
};
