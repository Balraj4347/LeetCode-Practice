//T.C : O(N)
//S.C : O(N)

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int n= ratings.size();
        if(n==1)return 1;
       vector<int> count(n,1);
        
        for(int i=0;i<n-1;i++){
            if(ratings[i] < ratings[i+1])
                count[i+1]= count[i]+1;
        }
        
        for(int i=n-1;i>0;i--){
            if(ratings[i] < ratings[i-1] && count[i-1] <= count[i])
                count[i-1]= count[i]+1;
        }
        
        return accumulate(count.begin(),count.end(),0);
        
    }
};
