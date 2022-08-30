class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        reverse(a.begin(),a.end());
        for(int i=0;i<a.size();i++){
            for(int j=0;j<i;j++){
                swap(a[i][j],a[j][i]);
            }
        }
    }
};