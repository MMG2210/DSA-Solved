class Solution {
public:
    /*int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(pq.size()<k)
                    pq.push(matrix[i][j]);
                else{
                    if(pq.top()>matrix[i][j]){
                        pq.pop();
                        pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top();
        TC = O(n*n*logk) SC = O(k)
    }*/
    int kthSmallest(vector<vector<int>>& matrix, int k){
        int n =matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        while(low<high){
            int mid = low + (high-low)/2;
            int count = 0;
            for(int i=0;i<n;i++){
                count+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            }
            if(count<k)low = mid+1;
            else high = mid;
        }
        return low;
    //TC = O(n*logk) SC = O(1)
    }
};