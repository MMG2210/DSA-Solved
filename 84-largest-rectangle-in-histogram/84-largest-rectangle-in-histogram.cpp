class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int N = h.size();
        vector<int> nse(N), pse(N);
        stack<int> st;
        
        for(int i=N-1;i>=0;i--){
            while(!st.empty() && h[st.top()]>=h[i])st.pop();
            nse[i]=st.empty()?N:st.top();
            st.push(i);
        }
        
        while(!st.empty())st.pop();
        
        for(int i=0;i<N;i++){
            while(!st.empty() && h[st.top()]>=h[i])st.pop();
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        
        int res = INT_MIN;
        
        for(int i=0;i<N;i++){
            res = max(res,(nse[i]-pse[i]-1)*(h[i]));
        }
        
        return res;
    }
};