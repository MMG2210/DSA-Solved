class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> st;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(st.empty() || st.top().first!=s[i])st.push({s[i],1});
            else{
                auto prev = st.top();
                st.pop();
                prev.second+=1;
                if(prev.second==k)continue;
                else{
                    st.push(prev);
                }
            }
        }
        
        string res="";
        
        while(!st.empty()){
            auto temp=st.top(); st.pop();
            int i=0;
            while(i<temp.second){
                i++;
                res+=temp.first;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};