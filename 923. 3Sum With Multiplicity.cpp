class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int answer=0;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int mod = 1000000007;
        for(int i=0;i<n-2;i++)
        {
         int lo=i+1,hi=n-1;   
            while(lo<hi){
                if(arr[lo]+arr[hi]+arr[i] == target){
                    int cntlo=1,cnthi=1;
                        while(lo<hi && arr[lo]==arr[lo+1]){cntlo++;lo++;}
                        while(lo<hi && arr[hi]==arr[hi-1]){cnthi++;hi--;}
                    
                    if(lo==hi)
                        answer= (answer + (cntlo*(cntlo-1)/2) )% mod;
                    else
                        answer = (answer + (cntlo*cnthi)) % mod;    
                    lo++;hi--;
                    
                    }
                else if(arr[i]+arr[lo]+arr[hi]<target)
                    lo++;
                else
                    hi--;
                }
                
            }
        
    return answer;
    }
};
