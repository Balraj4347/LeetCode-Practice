//O(n) with space O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    
      for(int i=0;i<nums.size();i++){
          int index = abs(nums[i]) -1;
          
          nums[index] *= -1;
          if(nums[index] > 0)
              return abs(nums[i]);
      }
        return -1;
        
    }
};
//O(nlogn)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    
        int beg=1,end=nums.size()-1;
        int count;
        while(beg<=end){
            int mid= beg+ (end-beg)/2;
            
            count=0;
            for(int i:nums)
                {
                if(i <= mid) 
                    count++;}
            
            if(count<=mid)
                beg= mid+1;
            else
                end=mid-1;
            
            
        }
        return beg;
        
        
    }
};
