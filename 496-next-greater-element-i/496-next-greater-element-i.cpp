class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        vector<int> nge(1e4+10);
        stack<int> st;
        st.push(n-1);
        nge[nums2[n-1]]=-1;
        for(int i=n-2;i>-1;i--){
            while(!st.empty() && nums2[st.top()]<=nums2[i])st.pop();
            nge[nums2[i]] = st.empty()?-1:nums2[st.top()];
            st.push(i);
        }
        
        vector<int> res;
        for(int i=0;i<nums1.size();i++){
            res.push_back(nge[nums1[i]]);
        }
        
        return res;
    }
};