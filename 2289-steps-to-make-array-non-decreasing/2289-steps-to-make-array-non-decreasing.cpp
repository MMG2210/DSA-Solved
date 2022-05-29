class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n=nums.size(),res=0;
        stack<pair<int,int>> st;
        st.push({nums[n-1],0});
        for(int i=n-2;i>=0;i--){
            int cnt=0;
            while(!st.empty() && nums[i]>st.top().first){
                cnt=max(cnt+1,st.top().second);
                st.pop();
            }
            res=max(res,cnt);
            st.push({nums[i],cnt});
        }
        return res;
    }
};