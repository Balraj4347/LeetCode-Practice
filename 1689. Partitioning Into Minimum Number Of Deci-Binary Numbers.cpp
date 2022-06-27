class Solution {
public:
    int minPartitions(string n) {
        
        int max= INT_MIN;
        for(char a:n){
            if(a-'0'  > max)
                max = a-'0';
        }
        return max;
        
    }
};
