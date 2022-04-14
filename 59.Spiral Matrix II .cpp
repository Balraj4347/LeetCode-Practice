class Solution {
public:
     vector<vector<int>> generateMatrix(int n) {
        
       vector<vector<int>> ans(n,vector<int>(n,0));
        int i=0,j=0; 
        int count=1;
        while(i<n && j<n){

        	
            int k=i,l=j;
            while(l < n-j){
            	
                ans[k][l]=count;
                count++;
                l++;
            }
            l--;
            k++;
            while(k < n-i){
            	
                ans[k][l]=count;
                count++;
                k++;
            }
            l--;k--;
            
            while(l >= j){
            	
            	ans[k][l]=count;
            	count++;
            	l--;
            }
         
            l++;
            k--;
            while(k > i){
            	
            	ans[k][l]=count;
            	count++;
            	k--;
            }
            
            
            i++;j++;
        }
        return ans;
}
};
