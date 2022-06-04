class Solution {
public:
    vector<vector<string>> ans;
    
    bool isSafe(int row, int col, vector<string>& board, int& n){
        int dupRow=row, dupCol=col;
        
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }
        row=dupRow;
        col=dupCol;
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        row=dupRow;
        col=dupCol;
        while(row<n && col>=0){
            if(board[row][col]=='Q')return false;
            row++;
            col--;
        }
        
        return true;
    }
    
    void rec(int col, vector<string>& board, int& n){
        if(col==n){
            ans.push_back(board);
        }
        
        for(int i=0;i<n;i++){
            if(isSafe(i,col,board,n)){
                board[i][col]='Q';
                rec(col+1,board,n);
                board[i][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        
        rec(0,board,n);
        return ans;
    }
};