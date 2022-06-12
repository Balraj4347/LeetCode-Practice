
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0;
        int n= nums.size();
        unordered_map<int,int> dict;
        int score=0;
        int temp=0;
        while(j<n){
            dict[nums[j]]++;
           
            while(dict.size()< j-i+1)
            {   temp= temp- nums[i];
                dict[nums[i]]--;
                if(dict[nums[i]]==0)
                    dict.erase(nums[i]);
                i++;
            }
            temp=temp+nums[j];
            score= max(score,temp);
            j++;
        }
        return score;
        
        
    }
};
