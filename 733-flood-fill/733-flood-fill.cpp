class Solution {
public:
    bool isValid(vector<vector<int>>& res,int i,int j,int oc){
        return i>=0 && i<res.size() && j>=0 && j<res[0].size() && res[i][j]==oc;
    }
    void dfs(vector<vector<int>>& res,int i,int j, int nc,int oc){
        if(!isValid(res,i,j,oc))return;
        res[i][j]=nc;
        dfs(res,i+1,j,nc,oc);
        dfs(res,i-1,j,nc,oc);
        dfs(res,i,j+1,nc,oc);
        dfs(res,i,j-1,nc,oc);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m=image.size(),n=image[0].size();
        int origColor = image[sr][sc];
        if(origColor==newColor)return image;
        dfs(image,sr,sc,newColor,origColor);
        return image;
    }
};