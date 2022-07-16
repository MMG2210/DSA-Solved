class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size(), res=INT_MAX;
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> >pq;
        long long runSum=0;
        for(int i=0;i<n;i++){
            runSum+=nums[i];
            if(runSum>=k){
                res=min(res,i+1);
            }
            while(!pq.empty() && runSum-pq.top().first>=k){
                auto top=pq.top(); pq.pop();
                res=min(res,i-top.second);
            }
            pq.push({runSum,i});
        }
        return res==INT_MAX?-1:res;
    }
};