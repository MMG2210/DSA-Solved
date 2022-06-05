class Solution {
public:
    set<vector<string>> ans;
    
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
            ans.insert(board);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(isSafe(i,col,board,n)){
                board[i][col]='Q';
                rec(col+1,board,n);
                board[i][col]='.';
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        
        rec(0,board,n);
        return ans.size();
    }
};