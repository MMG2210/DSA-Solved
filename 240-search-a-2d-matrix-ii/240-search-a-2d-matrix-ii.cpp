class Solution {
public:
    /*bool binarySearch(vector<vector<int>>& matrix, int row, int col, int target){
        int s = 0, e = col-1;
        if(target > matrix[row][e])return false;
        if(target < matrix[row][s])return false;
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
        
    This approach uses Binary Search on each row provided the target is greater than the smallest and lesser than largest elements of row. 
    Worst case Time Complexity is O(m*logn) Runtime = 184ms;
    Worst case Space Complexity is O(1) as no extra space is used;
    }*/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m  = matrix.size();
        int n = matrix[0].size();
        int r=0,c=n-1;
        while (r < m && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            }
            matrix[r][c] > target ? c-- : r++;
        }
        return false;
    //This approach uses the fact that the matrix is sorted in both column and rows.
    //So if target is smaller than top value of a column then check another col else check the next row of the same column
    //Worst case Time Complexity is O(m+n) Runtime = 160ms;
    //Worst case Space Complexity is O(1) as no extra space is used;
    }
};