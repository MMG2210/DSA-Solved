class Solution {
public:
    int countNeighbors(vector<vector<int>>& board, int i, int j, int m, int n) {
        int count = 0;
        
        for (int I = max(i-1, 0); I < min(i + 2, m); ++I)
            for (int J = max(j - 1, 0); J < min(j + 2, n); ++J) {
                if(i == I && j == J) continue;//Don't check the same element only neighbors.
                
                if(board[I][J] == 1 || board[I][J] == 2)//If it is alive or newly dead ie., alive in
                    count++;// the original state but dead in new/next state.
            }
                 
        return move(count);
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int countOfNeighbors = countNeighbors(board,i,j,n,m);
                if(board[i][j]==1){
                    if(countOfNeighbors<2 || countOfNeighbors>3){
                        board[i][j]=2;//2 means newly dead or dead in next state but alive in original
                    }
                }
                else if(board[i][j]==0){
                    if(countOfNeighbors==3)
                        board[i][j]=3;//3 means newly alive or alive in next state but dead in original
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]%=2;//since newly deads are 2, newly alive are 3,
                //2%2=0(dead) and similarly 3%2=1(alive).
            }
        }
    }//TC is O(m*n) while SC is O(1)
};