class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int beg=0, end=numbers.size()-1;
        vector<int>result(2,0);
    
        while(beg<end){
            int sum =numbers[beg]+numbers[end];
            if(sum < target)
                beg++;
            else if( sum> target)
                end--;
            else if(sum == target){
                break;
            }
        }
        result[0]=beg+1;
        result[1]=end+1;
        return result;
    }
};

