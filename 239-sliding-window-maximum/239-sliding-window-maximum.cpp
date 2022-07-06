class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> nge(n,n), res;
        stack<int> st;
        st.push(n-1);
        for(int i=n-2;i>-1;i--){
            while(!st.empty() && nums[i]>=nums[st.top()])st.pop();
            nge[i] = st.empty()?n:st.top();
            st.push(i);
        }
        
        int j=0;
        for(int i=0;i<=n-k;i++){
            if(j<i)j=i;
            while(nge[j]<i+k){
                j=nge[j];
            }
            res.push_back(nums[j]);
        }
        
        return res;
    }
};