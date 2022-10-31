class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& a) {
        int m = a.size(), n=a[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int x = a[i][j];
                int di = i, dj =j;
                while(di+1<m && dj+1<n){
                    if(a[di+1][dj+1]!=x)return false;
                    di++;
                    dj++;
                }
            }
        }
        return true;
    }
};