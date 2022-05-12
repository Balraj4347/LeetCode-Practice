class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int count=0;
        int size=nums.size();
        for(int i=0;i<size;i++){
            if(nums[i]== val)
                count++;
            else
                nums[i-count]=nums[i];
        }
        
        return size-count;
        
    }
};
