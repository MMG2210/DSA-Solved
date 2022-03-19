class Solution {
public:
    vector<int> minOperations(string b) {
        int n=b.size();
        vector<int> ans(n,0);
        if(!n)return ans;
        for(int i=0,cnt=0,ops=0;i<n;i++)
        {
            ans[i]+=ops;
            cnt+=(b[i]=='1')? 1:0;
            ops+=cnt;
        }
        for(int i=n-1,cnt=0,ops=0;i>=0;i--)
        {
            ans[i]+=ops;
            cnt+=(b[i]=='1')? 1:0;
            ops+=cnt;
        }
        return ans;
    }
};