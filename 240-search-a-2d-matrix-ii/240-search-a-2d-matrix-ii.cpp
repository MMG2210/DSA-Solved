class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int row, int col, int target){
        int s = 0, e = col-1;
        while(s<=e)
        {
            int m = s + (e-s)/2;
            if(matrix[row][m] == target)return true;
            else if (matrix[row][m] > target) e = m-1;
            else s = m+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row  = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i<row;i++)
            if(binarySearch(matrix,i,col,target))return true;
        return false;
    }
};