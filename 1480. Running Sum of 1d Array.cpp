class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int temp=0;
        int n=nums.size();
        vector<int> rslt(n,0);
        for(int i=0;i< n; i++){
            rslt[i]= temp + nums[i];
            temp=rslt[i];
            
        }
        return rslt;
    }
};

/*Runtime: 3 ms, faster than 76.56% of C++ online submissions for Running Sum of 1d Array.*/
