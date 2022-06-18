//T.C: O(2*(m*n)) S.c : O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m= matrix.size();
        int n= matrix[0].size();
        bool firstRow= false;
        bool firstColumn= false;
        for(int i=0; i<m ; i++ )
        {
            for(int j=0;j<n;j++)
             if(matrix[i][j]==0)
                {   if(i==0) firstRow= true;
                    if(j==0) firstColumn= true;
                  
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
                
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(firstColumn){
            for(int i=0;i<m;i++) matrix[i][0] = 0;
        }
        
        if(firstRow){
            for(int i=0;i<n;i++) matrix[0][i] = 0;
        }
   
        
       
    }
};

//T.C : O(2*(m*n)) S.C : O(m+n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m= matrix.size();
        int n= matrix[0].size();
        unordered_set<int> X;
        unordered_set<int> Y;
    
        for(int i=0; i<m ; i++ )
        {
            for(int j=0;j<n;j++)
            {
                
                if(matrix[i][j]==0)
                {   X.insert(i);
                    Y.insert(j);
                    
              
                }
                
            }
        }
        
        for(int i:X)
            {
                for(int j=0;j<n;j++)
                    matrix[i][j]=0;
            }
        

        for(int j:Y)
        {         
            for(int i=0;i<m;i++)
                matrix[i][j]=0;
        }
            
        
       
    }
};
