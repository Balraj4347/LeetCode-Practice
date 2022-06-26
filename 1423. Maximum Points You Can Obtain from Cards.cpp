class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int n= cardPoints.size();
        int l=0,r=n-k;
        int sum=0,total=0;
        for(int i=0;i<r;i++)
        {
            sum+=  cardPoints[i];
            total+= cardPoints[i]; 
        }
        int minSum=sum;
        while(r<n){
            sum += (cardPoints[r]- cardPoints[l]);
            total+= cardPoints[r];
            if(minSum > sum)
                minSum= sum;
            r++;
            l++;
            
        }
      return total-minSum;
    }
};
