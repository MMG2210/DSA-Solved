class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int t) {
        int res=0;
        int m=mat.size(), n=mat[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                unordered_map<int,int> mpp;
                mpp[0]=1;
                int sum=0;
                for(int k=0;k<m;k++){
                    sum+=mat[k][j]-(i>0?mat[k][i-1]:0);
                    res+=mpp.find(sum-t)!=mpp.end()?mpp[sum-t]:0;
                    mpp[sum]++;
                }
            }
        }
        return res;
    }
};