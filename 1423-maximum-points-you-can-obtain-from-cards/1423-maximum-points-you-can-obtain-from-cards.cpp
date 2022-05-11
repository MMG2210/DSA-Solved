class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res=0, sum=0, n=cardPoints.size();
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        
        res=sum;
        
        for(int i=0;i<k;i++){
            sum -= cardPoints[k-i-1] - cardPoints[n-i-1];
            res=max(res,sum);
        }
        
        return res;
    }
};