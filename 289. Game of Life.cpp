class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int>> posn;
        int m=board.size();
        int n;
        if(m>0) n=board[0].size();
        else n=0;
        
        vector<vector<int>> temp=board;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            	
                int k=i-1;
                if(k<0){k=0;}
           
                int count=0;
                
                while(k <= i+1 && k<m)
                    {		int l=j-1;
                    	  if(l<0){l=0;}
                    	while(l <= j+1 && l<n)
                                       
                   		{   if(k==i && l==j){}             				
                            else if(board[k][l]==1)
								count++;
                            l++;			
						}
						k++;
					}
			
					if(count < 2 || count>3)
						temp[i][j]=0;
					else if(count==3)
						temp[i][j]=1;
                
            }
        }
        board=temp;
    }
};
