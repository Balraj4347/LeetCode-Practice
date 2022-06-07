class Solution {
public:
	int findLength(vector<int>& A, vector<int>& B) {
		int m = size(A), n = size(B), ans = 0, dp[m+1][n+1]; 
		memset(dp, -1, sizeof dp);
		for(int i = 0; i < m; i++) {
			for(int j = 0, len = 0; j < n; j++) {
				if(dp[i][j] == -1) {
					while(i + len < m and j + len < n and A[i+len] == B[j+len]) len++;
					while(len) dp[i + len][j + len] = len--;  
				}
				ans = max(ans, dp[i][j]);
			}
		}
		return ans;
	}
};	

//brute force
// {
//     int ans=0;
//     for(int i=0;i<nums1.size();i++)
//         for(int j=0;j<nums2.size();j++)
//         {
//             if( nums1[i] == nums2[j] )
//             {
//                 int temp1=i,temp2=j;
//                 int count=0;
//     while(temp1<nums1.size() && temp2<nums2.size() && nums1[temp1++]==nums2[temp2++])
//                     count++;
//                 if(ans<count)
//                     ans=count;
//             }
            
//         }
//         return ans;
// }

//recursive code
// {
//         int solve(vector<int>& nums1, vector<int>& nums2,int i,int j)
//     {   
//         if(i<0|| j<0 )
//             return 0;
      
//         int temp=0;
//         if(nums1[i] != nums2[j])
//              return max(solve(nums1,nums2,i-1,j),solve(nums1,nums2,i,j-1));
        
//         int rslt=0;
//         while( i>=0 && j>=0 && nums1[i--] == nums2[j--])
//             rslt++;
        
//         return max(temp,rslt);
         
//     }
    
//     int findLength(vector<int>& nums1, vector<int>& nums2) {
//         int m= nums1.size();
//         int n= nums2.size();
//         return solve(nums1,nums2,m-1,n-1);
    
//     }
// }

//first attemp dp
// {
//     int ans=0;
//     int solve(vector<int>& nums1, vector<int>& nums2,int i,int j,
//               vector<vector<int>>& dp)
//     {   
//         if(i<0|| j<0 )
//             return 0;
        
//         if(dp[i][j] != -1) return dp[i][j];
//         solve(nums1,nums2,i-1,j,dp), solve(nums1,nums2,i,j-1,dp);
        
//         dp[i][j]= nums1[i]==nums2[j] ? solve(nums1,nums2,i-1,j-1,dp)+1 : 0;
//         ans= max(ans,dp[i][j]);
//         return dp[i][j];
         
//     }
    
//     int findLength(vector<int>& nums1, vector<int>& nums2) {
//         int m= nums1.size();
//         int n= nums2.size();
//         vector<vector<int>> dp(m,vector<int>(n,-1));
//         solve(nums1,nums2,m-1,n-1,dp);
//         return ans;
    
//     }
    
// } it gave a 1100ms run time ☹︎
