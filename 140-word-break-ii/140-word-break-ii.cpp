class Solution {
public:
    unordered_set<string> dict;
    vector<string> res;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string& w:wordDict){
            dict.insert(w);
        }
        string curr="";
        solve(0,s,curr);
        return res;
    }
    void solve(int ind, string& s, string curr){
        if(ind==s.size()){
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        string str="";
        for(int i=ind;i<s.size();i++){
            str.push_back(s[i]);
            if(dict.count(str)){
                solve(i+1, s,curr+str+" ");
            }
        }
    }
};