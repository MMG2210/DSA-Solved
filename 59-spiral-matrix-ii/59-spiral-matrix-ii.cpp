class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n,0));
        long long i=1,sr=0,er=n-1,sc=0,ec=n-1;
        while(sr<=er && sc<=ec){
            for(long long j=sc;j<=ec;j++){
                res[sr][j]=i++;//l->r
            }
            sr++;
            for(long long j=sr;j<=er;j++){
                res[j][ec]=i++;//top->down
            }
            ec--;
            for(long long j=ec;j>=sc;j--){
                res[er][j]=i++;//r-->l
            }
            er--;
            for(long long j=er;j>=sr;j--){
                res[j][sc]=i++;//bot->up
            }
            sc++;
        }
        return res;
    }
};