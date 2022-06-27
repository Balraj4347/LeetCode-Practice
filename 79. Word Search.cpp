class Solution {
public:
    int n, m;
    vector<vector<bool>> vis;
    bool dfs(vector<vector<char>>& board,string word,int i,int j,int index){
        
        if(board[i][j]== word[index]){
            
            vis[i][j]=true;
            if(index== word.length()-1)
                return true;
            if(i-1>=0 && vis[i-1][j]==false)
                if(dfs(board,word,i-1,j,index+1))
                    return true;
            if(i+1<m && vis[i+1][j]==false)
                if(dfs(board,word,i+1,j,index+1))
                    return true;
             if(j-1>=0 && vis[i][j-1]==false)
                if(dfs(board,word,i,j-1,index+1))
                    return true;
             if(j+1< n && vis[i][j+1]==false)
                if(dfs(board,word,i,j+1,index+1))
                    return true;
            
            vis[i][j]=false;
        }
        
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        m= board.size();
        n= board[0].size();
        vis= vector<vector<bool>>(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                 if(dfs(board, word, i, j, 0))
                    return true;
        }
        
        return false;
    }
};
