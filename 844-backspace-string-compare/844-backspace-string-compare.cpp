class Solution {
public:
    string helper(string s)
    {
        stack<char>stk;
        for(auto it:s)
        {
            if(it!='#')
            {
                stk.push(it);
            }
            else if(!stk.empty())
            {
                stk.pop();
            }
        }
        string ans="";
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
    bool backspaceCompare(string S, string T) 
    {
        return helper(S)==helper(T);
    }
};