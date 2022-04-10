class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(string& op:ops){
            if(op=="+"){
                int temp=0;
                int n1=st.top();st.pop();
                int n2=st.top();
                temp+=st.top() + n1;
                st.push(n1);
                st.push(temp);
            }
            else if(op=="D"){
                int temp = 2*st.top();
                st.push(temp);
            }
            else if(op=="C"){
                st.pop();
            }
            else{
                st.push(stoi(op));
            }
        }
        int res=0;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};