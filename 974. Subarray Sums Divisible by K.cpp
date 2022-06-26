class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        vector<int> freq(k,0);
        freq[0]=1;
        int sum=0;
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            
            int rem = sum%k;
            if(rem<0) rem= rem+k;
            
            count= count+ freq[rem];
            freq[rem]++;
        }
        
        return count;
        
        
    }
};
