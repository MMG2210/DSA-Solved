class Solution {
public:
    string decodeString(string s) {
                stack<char> st;   // char stack        
        for(int itr = 0; itr < s.size(); itr++){
            if(s[itr] == ']'){
                string str = "";
                while(st.top() != '['){
                    str = st.top() + str;
                    st.pop();
                }                
                st.pop();
                
                string times = "";
                while(!st.empty() && isdigit(st.top())){
                    times = st.top() + times;
                    st.pop();
                }
                
                int count = stoi(times);
                
                while(count--){
                    for(int jtr = 0; jtr < str.size(); jtr++){
                        st.push(str[jtr]);
                    }
                }
            }
            else{
                st.push(s[itr]);
            }
        }
        
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};