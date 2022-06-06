
class Solution {
public:
    int solve(int i,int j, int x,int y,vector<vector<int>>& steps)
    {
        
        if(i==x && j==y)
            return 1;
        if(steps[i][j] != -1)
            return steps[i][j];
        steps[i][j]= (i<x ? solve(i+1,j,x,y,steps):0) +
                     (j<y ? solve(i,j+1,x,y,steps):0);
        
        return steps[i][j];
    }
    int uniquePaths(int m, int n) {
       
        vector<vector<int>> steps(m,vector<int>(n,-1));
         
        return solve(0,0,m-1,n-1,steps);
        
    }
};
