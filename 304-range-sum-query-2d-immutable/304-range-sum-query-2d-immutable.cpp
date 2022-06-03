class NumMatrix {
public:
    vector<vector<int>> preMat;
    int m,n;
    NumMatrix(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        preMat.resize(m,vector<int>(n));
        for(int i=0;i<m;i++){
            preMat[i][0]=matrix[i][0];
            for(int j=1;j<n;j++){
                preMat[i][j]=preMat[i][j-1]+matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res=0;
        for(int i=row1;i<=row2;i++){
            if(col1)res+=(preMat[i][col2]-preMat[i][col1-1]);
            else res+=preMat[i][col2];
            //cout<<preMat[i][col2]-preMat[i][col1]<<' '<<res<<"\n";
        }
        
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */