class Solution {
public:
    int util(vector<vector<int>>& triangle, int h, int j, vector<vector<int>>& dp){
        if(h==triangle.size())return 0;
        if(dp[h][j]!=-1)return dp[h][j];
        return dp[h][j]=triangle[h][j]+min(util(triangle,h+1,j,dp),util(triangle,h+1,j+1,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int h=triangle.size(),j;
        j=h;
        vector<vector<int>> v(h,vector<int> (j,0));
         v[0][0]=triangle[0][0];
         for(int i=1;i<h;i++)
         {
             for(int j=0;j<triangle[i].size();j++)
             {
                 if(j==0) v[i][j]=v[i-1][j]+triangle[i][j];
                 else if(j==triangle[i].size()-1) v[i][j]=v[i-1][j-1]+triangle[i][j];
                 else
                 v[i][j]=min(v[i-1][j-1],v[i-1][j])+triangle[i][j];
             }
              
         }
         
        return *min_element(v[h-1].begin(),v[h-1].end());
    }
};