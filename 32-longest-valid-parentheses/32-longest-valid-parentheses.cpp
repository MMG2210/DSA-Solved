class Solution {
public:
    int longestValidParentheses(string s) {
//         stack<int> st;
//         st.push(-1);
//         int res=0;
//         for(int i=0;i<s.size();i++){
//             if(s[i]=='('){
//                 st.push(i);
//             }
//             else{
//                 st.pop();
//                 if(st.empty()){
//                     st.push(i);
//                 }
//                 else res=max(res,i-st.top());
//             }
//         }
        
//         return res;
        int res=0,left=0,right=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')left++;
            else right++;
            if(left==right)res=max(res,right*2);
            else if(right>left){
                left=right=0;
            }
        }
        left=right=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(')left++;
            else right++;
            if(left==right)res=max(res,left*2);
            else if(right<left){
                left=right=0;
            }
        }
        
        return res;
    }
};