class Solution {
public:
    bool isValid(vector<vector<char>>& board, int i, int j){
        return (i>=0 && i< board.size() && j>=0 && j<board[0].size() && board[i][j]=='O');
    }
    void dfs(vector<vector<char>>& board, int i, int j, char c){
        if(!isValid(board,i,j))return;
        board[i][j]=c;
        
        dfs(board,i+1,j,c);
        dfs(board,i,j+1,c);
        dfs(board,i-1,j,c);
        dfs(board,i,j-1,c);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')dfs(board,i,0,'*');
            if(board[i][n-1]=='O')dfs(board,i,n-1,'*');
        }
        
        for(int i=0;i<n;i++){
            if(board[0][i]=='O')dfs(board,0,i,'*');
            if(board[m-1][i]=='O')dfs(board,m-1,i,'*');
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0 && i<m-1 && j>0 && j<n-1 && board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='*')board[i][j]='O';
            }
        }
    }
};