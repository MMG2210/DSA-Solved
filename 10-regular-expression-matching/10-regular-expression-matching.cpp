class Solution {
public:
    unordered_map<string,int> dp;
    
    bool rec(string &s, string &p, int i, int j){
        string key = to_string(i) + to_string(j);
        if(i<0 && j<0)return true;
        if(i<0 && p[j]=='*')return rec(s,p,i,j-2);
        if(i<0 || j<0)return false;
        if(dp.count(key))return dp[key];
        if(s[i]==p[j])return dp[key] = rec(s,p,i-1,j-1);
        else{
            if(p[j]=='*'){
                if(s[i]==p[j-1] || p[j-1]=='.'){
                    return dp[key] = (rec(s,p,i-1,j)||rec(s,p,i,j-2));
                }
                else return dp[key] = rec(s,p,i,j-2);
            }
            else if(p[j]=='.')return dp[key] = rec(s,p,i-1,j-1);
            else return dp[key] = false;
        }
    }
    
    bool isMatch(string s, string p) {

        return rec(s,p,s.size()-1,p.size()-1);
    }
};