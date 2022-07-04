class Solution {
public:
    int n;
    
    int getNextJob(vector<vector<int>>& jobs, int i){
        int l=0, h=n-1, res=-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(jobs[mid][0]>=jobs[i][1]){
                res=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
    
    int solve(vector<vector<int>>& jobs, vector<int>& dp, int i){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int take=jobs[i][2];
        int next=getNextJob(jobs,i);
        if(next!=-1)take += solve(jobs, dp, next);
        int skip = solve(jobs, dp, i+1);
        return dp[i]=max(take,skip);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        vector<vector<int>> jobs(n);
        for(int i=0;i<n;i++){
            jobs[i]={startTime[i],endTime[i],profit[i]};
        }
        sort(begin(jobs),end(jobs));
        vector<int> dp(n,-1);
        return solve(jobs, dp, 0);
    }
};