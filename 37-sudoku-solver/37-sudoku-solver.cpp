class Solution {
public:
    bool solve(vector<vector<char>>& b){
        //int m=b.size(),n=b[0].size();
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(b[i][j]!='.')continue;
                for(char a='1';a<='9';a++){
                    if(isValid(b,a,i,j)){
                        b[i][j]=a;
                        if(solve(b))return true;
                        else b[i][j]='.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& b, char c, int row, int col){
        for(int i=0;i<9;i++){
            if(b[row][i]==c)return false;
            if(b[i][col]==c)return false;
            if(b[3*(row/3)+i/3][3*(col/3)+i%3]==c)return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};