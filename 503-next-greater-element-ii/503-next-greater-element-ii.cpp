class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n=nums.size();
        vector<int> res(n,-1);
        
        for(int i=0;i<n*2;i++){
            int idx = i>=n?i-n:i;
            while(!st.empty() && nums[st.top()]<nums[idx]){
                res[st.top()]=nums[idx];
                st.pop();
            }
            st.push(idx);
        }
            
        return res;
    }
};